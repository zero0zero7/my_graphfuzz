/*
Header files for AST suppport
/usr/lib/llvm-16/include/clang/AST
*/

// Declares llvm::cl::extrahelp.
#include "llvm/Support/CommandLine.h"

#include "clang/AST/ASTConsumer.h"
#include <clang/AST/ParentMapContext.h>
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/Tooling.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/AST/Expr.h"
#include "clang/AST/Decl.h"

#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

#include "json.hpp"
using json = nlohmann::json;
using namespace clang;
using namespace std;

// map of danger_op : [func_names]
unordered_map<string, vector<string>> dangerous;
// list of func_names (intermediate data struct to build map)
std::vector<std::string>* funcs = new std::vector<std::string>();


class FindNamedClassVisitor : public RecursiveASTVisitor<FindNamedClassVisitor> {
public:
    explicit FindNamedClassVisitor(ASTContext *Context): Context(Context) {}

    template<typename T> // T should be Stmt or Decl
    void recursive_parent(const T* node) {
        DynTypedNodeList parent_list = Context->getParents(*node);
        if (parent_list.size() >= 1){
            for (int i = 0; i< parent_list.size(); i++ ){
                const CXXMethodDecl* parent_method_decl =  parent_list[i].get<CXXMethodDecl>();
                if (parent_method_decl != NULL) {
                    funcs->push_back(parent_method_decl->getQualifiedNameAsString());
                }
                else {
                    const Decl* decl = parent_list[i].get<Decl>();
                    if (decl != NULL) {
                        this->recursive_parent<Decl>(decl);
                    }
                    else {
                        const Stmt* stmt = parent_list[i].get<Stmt>();
                        this->recursive_parent<Stmt>(stmt);
                    }
                }
            }
        }
    }

    bool VisitCallExpr(CallExpr* callExpr) {
        // Decl* callee_decl = callExpr->getCalleeDecl();
        FunctionDecl* func_decl = callExpr->getDirectCallee();
        if (func_decl != NULL) {
            string func_name = func_decl->getNameAsString();
            // TODO: abstract the func_name of interest
            if (func_name == "memset") { 
                this->recursive_parent<Stmt>(callExpr);
                dangerous[func_name] = *funcs;
                funcs->clear();
            }
        }
        return true;
    }

private:
    ASTContext *Context;
};


class FindNamedClassConsumer : public clang::ASTConsumer {
public:
    explicit FindNamedClassConsumer(ASTContext *Context)
        : Visitor(Context) {}

    virtual void HandleTranslationUnit(clang::ASTContext &Context) {
        // Traversing the translation unit decl via a RecursiveASTVisitor will visit all nodes in the AST.
        Visitor.TraverseDecl(Context.getTranslationUnitDecl());
    }
private:
    // A RecursiveASTVisitor implementation.
    FindNamedClassVisitor Visitor;
};


class FindNamedClassAction : public clang::ASTFrontendAction {
public:
    virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
        clang::CompilerInstance &Compiler, llvm::StringRef InFile) {
        llvm::outs() << "==== InFile " << InFile << "\n";
        return std::make_unique<FindNamedClassConsumer>(&Compiler.getASTContext());
    }
};


// CommonOptionsParser declares HelpMessage with a description of the common
// command-line options related to the compilation database and input files.
// It's nice to have this help message in all tools.
static llvm::cl::extrahelp CommonHelp(clang::tooling::CommonOptionsParser::HelpMessage);

// A help message for this specific tool can be added afterwards.
// static cl::extrahelp MoreHelp("\nMore help text...\n");

// Apply a custom category to all command-line options so that they are the
// only ones displayed.
static llvm::cl::OptionCategory MyToolCategory("my-tool options");

int main(int argc, const char **argv) {
// int run_parser(int argc, const char **argv) {
    #if 0
    if (argc > 1) {
        clang::tooling::runToolOnCode(std::make_unique<clang::SyntaxOnlyAction>(), "class X {};");
    }
    #endif

    // CommonOptionsParser::create will parse arguments and create a CompilationDatabase.
    auto ExpectedParser = clang::tooling::CommonOptionsParser::create(argc, argv, MyToolCategory);
    if (!ExpectedParser) {
        // Fail gracefully for unsupported options.
        llvm::errs() << ExpectedParser.takeError();
        return 1;
    }
    clang::tooling::CommonOptionsParser& OptionsParser = ExpectedParser.get();

    // to retrieve CompilationDatabase and the list of input file paths.
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                    OptionsParser.getSourcePathList());
    Tool.run(clang::tooling::newFrontendActionFactory<FindNamedClassAction>().get());

    json j;
    for (auto op_func: dangerous) {
        
        for (auto func: op_func.second) {
            // j.push_back({op_func.first, func});
            j[op_func.first].push_back(func);
        }
    }
    std::ofstream op("risky.json");
    op << j << std::endl;
}

