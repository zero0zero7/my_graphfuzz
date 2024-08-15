

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


/* CPPScope(name=(auto) A::int get_money();) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    A *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->get_money();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) A::char ret_b();) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    A *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->ret_b();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) A::void set_money(int x);) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    A *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->set_money(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) A::char A::ret_a();) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    A *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->A::ret_a();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) A::~A();) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    {" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) B::B();) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    B *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new B();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) B::void b_func();) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    B *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->b_func();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) B::int get_money();) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    B *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->get_money();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) B::char ret_b();) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    B *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->ret_b();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) B::void set_money(int x);) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    B *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->set_money(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) B::char A::ret_a();) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    B *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->A::ret_a();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) B::~B();) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    {" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) C::C();) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    C *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new C();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) C::int get_money();) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    C *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->get_money();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) C::int ret_a();) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    C *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->ret_a();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) C::char ret_b();) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    C *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->ret_b();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) C::void set_money(int x);) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    C *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->set_money(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) C::~C();) */
extern "C" void shim_18(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    {" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) D::void b_func();) */
extern "C" void shim_19(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    D *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->b_func();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) D::D();) */
extern "C" void shim_20(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    D *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new D();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) D::int get_money();) */
extern "C" void shim_21(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    D *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->get_money();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) D::int ret_a();) */
extern "C" void shim_22(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    D *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->ret_a();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) D::char ret_b();) */
extern "C" void shim_23(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    D *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->ret_b();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) D::void set_money(int x);) */
extern "C" void shim_24(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    D *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->set_money(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) D::~D();) */
extern "C" void shim_25(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    {" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) W::int get_money();) */
extern "C" void shim_26(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    W *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->get_money();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) W::char ret_b();) */
extern "C" void shim_27(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    W *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->ret_b();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) W::void set_money(int x);) */
extern "C" void shim_28(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    W *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->set_money(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) W::W();) */
extern "C" void shim_29(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    W *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new W();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) W::char A::ret_a();) */
extern "C" void shim_30(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    W *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->A::ret_a();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) W::~W();) */
extern "C" void shim_31(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    {" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) X::int get_money();) */
extern "C" void shim_32(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    X *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->get_money();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) X::char ret_b();) */
extern "C" void shim_33(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    X *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->ret_b();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) X::void set_money(int x);) */
extern "C" void shim_34(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    X *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->set_money(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) X::X();) */
extern "C" void shim_35(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    X *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new X();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) X::char A::ret_a();) */
extern "C" void shim_36(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    X *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->A::ret_a();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) X::~X();) */
extern "C" void shim_37(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);

    std::cout << "    {" << std::endl;

    std::cout << "        delete " << "var_" << _i0 << ";" << std::endl;

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) Y::int get_money();) */
extern "C" void shim_38(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Y *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->get_money();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) Y::char ret_b();) */
extern "C" void shim_39(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Y *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->ret_b();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) Y::void set_money(int x);) */
extern "C" void shim_40(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Y *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->set_money(" << _a0 << ");\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) Y::Y();) */
extern "C" void shim_41(void **in_ref, void **out_ref, const char *context) {
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Y *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _o0 << " = new Y();" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) Y::char A::ret_a();) */
extern "C" void shim_42(void **in_ref, void **out_ref, const char *context) {
    unsigned long _i0 = reinterpret_cast<unsigned long>(in_ref[0]);
    unsigned long _o0 = CURR_ID++;
    std::cout << "    Y *var_" << _o0 << ";" << std::endl;

    std::cout << "    {" << std::endl;

    std::cout << "        " << "var_" << _i0 << "->A::ret_a();\n        " << "var_" << _o0 << " = " << "var_" << _i0 << ";" << std::endl;
    out_ref[0] = reinterpret_cast<void *>(_o0);

    std::cout << "    }" << std::endl;
}


/* CPPScope(name=(auto) Y::~Y();) */
extern "C" void shim_43(void **in_ref, void **out_ref, const char *context) {
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
    &shim_23,
    &shim_24,
    &shim_25,
    &shim_26,
    &shim_27,
    &shim_28,
    &shim_29,
    &shim_30,
    &shim_31,
    &shim_32,
    &shim_33,
    &shim_34,
    &shim_35,
    &shim_36,
    &shim_37,
    &shim_38,
    &shim_39,
    &shim_40,
    &shim_41,
    &shim_42,
    &shim_43,
};

