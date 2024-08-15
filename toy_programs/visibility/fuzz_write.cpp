

#include <string.h>
#include <string>
#include <iostream>
#include <unordered_map>

unsigned long CURR_ID = 0;

extern "C" void __attribute__((visibility ("default"))) global_init(int *argc, char ***argv) {
    char **new_argv = (char **)malloc((*argc + 2) * sizeof(char *));
    memcpy(new_argv, *argv, sizeof(*new_argv) * *argc);
    new_argv[*argc] = (char *)"-detect_leaks=0";
    new_argv[*argc + 1] = 0;
    (*argc)++;
    *argv = new_argv;
}

extern "C" void __attribute__((visibility ("default"))) shim_init() {
    CURR_ID = 0;

    std::cout << "#include \"lib.h\"\n" << std::endl;
    std::cout << "\n#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))\n\nstruct GFUZZ_BUNDLE {\npublic:\n    void *active;\n    void *inactive;\n    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {}\n};\n\n#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)\n" << std::endl;

    std::cout << "int main() {" << std::endl;
}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {
    std::cout << "}" << std::endl;
}

// placeholder for build_cast_map (so that fuzz_write.cpp can compile)
// will not generate source code for casting (no corresponding shim)
typedef void (*cast_func)(void**, void**);
void build_cast_map(std::unordered_map<unsigned int, std::unordered_map<unsigned int, cast_func>>* cast_map) {return;}



/* CPPScope(name=(auto) A::A();) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    A *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new A();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) A::A(double d);) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    double _a0;
    memcpy(&_a0, context + 0, sizeof(double));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    A *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new A(" << _a0 << ");" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) A::double GetBalance();) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    A *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->GetBalance();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) A::double GetBalanceFrom(A * a);) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    A *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    A *var_" << _o1 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->GetBalanceFrom(" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) A::~A();) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    {" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) ClassB::int b_public_get();) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    ClassB *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->b_public_get();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) ClassB::ClassB();) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    ClassB *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new ClassB();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) ClassB::~ClassB();) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    {" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) ClassC::ClassC();) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    ClassC *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new ClassC();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) ClassC::double GetBalance();) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    ClassC *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->GetBalance();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) ClassC::double GetBalanceFrom(A * a);) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    ClassC *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    A *var_" << _o1 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->GetBalanceFrom(" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) ClassC::~ClassC();) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    {" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) ClassE::ClassE();) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    ClassE *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new ClassE();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) ClassE::~ClassE();) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    {" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) ClassX::ClassX();) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    ClassX *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new ClassX();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) ClassX::~ClassX();) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    {" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) W::double GetBalance();) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    W *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->GetBalance();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) W::double GetBalanceFrom(A * a);) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _i1 = reinterpret_cast<unsigned long>(in_ref[1]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    W *var_" << _o0 << ";" << std::endl;
    unsigned long _o1 = CURR_ID++;
    std::cout << "    A *var_" << _o1 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->GetBalanceFrom(" << "var_" << _i1 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";\n        " << "var_" << _o1 << " = " << "var_" << _i1 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) W::W();) */
extern "C" void shim_18(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    W *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new W();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) W::int w_public_get();) */
extern "C" void shim_19(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    W *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->w_public_get();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) W::~W();) */
extern "C" void shim_20(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    {" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) Y::Y();) */
extern "C" void shim_21(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Y *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new Y();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) Y::~Y();) */
extern "C" void shim_22(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    {" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    }" << std::endl;
}


void __attribute__((visibility ("default"))) (*FUZZER_SHIMS[])(void **, void **, const char *) = {
    &shim_0,
    &shim_1,
    &shim_2,
    &shim_3,
    &shim_4,
    &shim_5,
    &shim_6,
    &shim_7,
    &shim_8,
    &shim_9,
    &shim_10,
    &shim_11,
    &shim_12,
    &shim_13,
    &shim_14,
    &shim_15,
    &shim_16,
    &shim_17,
    &shim_18,
    &shim_19,
    &shim_20,
    &shim_21,
    &shim_22,
};

