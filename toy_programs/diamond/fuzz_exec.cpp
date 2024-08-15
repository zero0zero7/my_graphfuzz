#include "lib.h"


#include <string.h>
#include <stdlib.h>
#include <cstdint>
#include <unordered_map>
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;
//using namespace std;

extern "C" int graphfuzz_try();
extern "C" void graphfuzz_bail();

extern "C" void __attribute__((visibility ("default"))) global_init(int *argc, char ***argv) {

}

extern "C" void __attribute__((visibility ("default"))) shim_init() {

}

extern "C" void __attribute__((visibility ("default"))) shim_finalize() {

}


#define MAKE(t) static_cast<t *>(calloc(sizeof(t), 1))

struct GFUZZ_BUNDLE {
public:
    void *active;
    void *inactive;
    GFUZZ_BUNDLE(void *_active, void *_inactive): active(_active), inactive(_inactive) {}
};

#define BUNDLE(a,b) new GFUZZ_BUNDLE((void *)a, (void *)b)



template <class B, class D> void __attribute__((visibility ("default"))) cast_helper(void** in, void** out) {
    D* d = reinterpret_cast<D*>(in[0]);
    // B* b = dynamic_cast<B*>(d);
    B* b = (B*)d;
    out[0] = reinterpret_cast<void *>(b);
}

typedef void (*cast_func)(void**, void**);

void build_cast_map(std::unordered_map<unsigned int, std::unordered_map<unsigned int, cast_func>>* cast_map) {
json sch;
std::ifstream sch_in(std::string("schema.json"));
sch_in >> sch;
std::unordered_map<std::string, unsigned int> name_id;
for (size_t i=0; i<sch["types"].size(); ++i) {
    name_id[sch["types"][i]["name"]] = ((sch["types"])[i])["id"];
}
#define BASE2DERIVED(Base, Derived) { \
    unsigned b_id = name_id[#Base], \
        d_id = name_id[#Derived]; \
    /* remembers the instantiated cast */ \
    (*cast_map)[b_id][d_id] = cast_helper<Base,Derived>; \
}
#include "classpairs.inc"
#undef BASE2DERIVED
}


/* CPPScope(name=(auto) A::A();) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    A *_o0;
    _o0 = new A();
    
                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) A::int get_num();) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    A *_i0 = reinterpret_cast<A *>(in_ref[0]);
    A *_o0;
    _i0->get_num();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) A::char ret_b();) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    A *_i0 = reinterpret_cast<A *>(in_ref[0]);
    A *_o0;
    _i0->ret_b();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) A::char A::ret_a();) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    A *_i0 = reinterpret_cast<A *>(in_ref[0]);
    A *_o0;
    _i0->A::ret_a();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) A::~A();) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    A *_i0 = reinterpret_cast<A *>(in_ref[0]);
    delete _i0;
    
                    
}


/* CPPScope(name=(auto) B::B();) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    B *_o0;
    _o0 = new B();
    
                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) B::void b_func();) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    B *_i0 = reinterpret_cast<B *>(in_ref[0]);
    B *_o0;
    _i0->b_func();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) B::int get_num();) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    B *_i0 = reinterpret_cast<B *>(in_ref[0]);
    B *_o0;
    _i0->get_num();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) B::char ret_b();) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    B *_i0 = reinterpret_cast<B *>(in_ref[0]);
    B *_o0;
    _i0->ret_b();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) B::char A::ret_a();) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    B *_i0 = reinterpret_cast<B *>(in_ref[0]);
    B *_o0;
    _i0->A::ret_a();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) B::~B();) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    B *_i0 = reinterpret_cast<B *>(in_ref[0]);
    delete _i0;
    
                    
}


/* CPPScope(name=(auto) C::C();) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    C *_o0;
    _o0 = new C();
    
                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) C::int get_num();) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    C *_i0 = reinterpret_cast<C *>(in_ref[0]);
    C *_o0;
    _i0->get_num();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) C::int ret_a();) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    C *_i0 = reinterpret_cast<C *>(in_ref[0]);
    C *_o0;
    _i0->ret_a();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) C::char ret_b();) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    C *_i0 = reinterpret_cast<C *>(in_ref[0]);
    C *_o0;
    _i0->ret_b();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) C::~C();) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    C *_i0 = reinterpret_cast<C *>(in_ref[0]);
    delete _i0;
    
                    
}


/* CPPScope(name=(auto) D::void b_func();) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    D *_i0 = reinterpret_cast<D *>(in_ref[0]);
    D *_o0;
    _i0->b_func();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) D::D();) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
    D *_o0;
    _o0 = new D();
    
                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) D::int get_num();) */
extern "C" void shim_18(void **in_ref, void **out_ref, const char *context) {
    D *_i0 = reinterpret_cast<D *>(in_ref[0]);
    D *_o0;
    _i0->get_num();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) D::int ret_a();) */
extern "C" void shim_19(void **in_ref, void **out_ref, const char *context) {
    D *_i0 = reinterpret_cast<D *>(in_ref[0]);
    D *_o0;
    _i0->ret_a();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) D::char ret_b();) */
extern "C" void shim_20(void **in_ref, void **out_ref, const char *context) {
    D *_i0 = reinterpret_cast<D *>(in_ref[0]);
    D *_o0;
    _i0->ret_b();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) D::~D();) */
extern "C" void shim_21(void **in_ref, void **out_ref, const char *context) {
    D *_i0 = reinterpret_cast<D *>(in_ref[0]);
    delete _i0;
    
                    
}


/* CPPScope(name=int get_num_0D()) */
extern "C" void shim_22(void **in_ref, void **out_ref, const char *context) {
    E *_i0 = reinterpret_cast<E *>(in_ref[0]);
    E *_o0;
    ((D *)_i0)->get_num();
    _o0 = _i0;
    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=int get_num_1C()) */
extern "C" void shim_23(void **in_ref, void **out_ref, const char *context) {
    E *_i0 = reinterpret_cast<E *>(in_ref[0]);
    E *_o0;
    ((C *)_i0)->get_num();
    _o0 = _i0;
    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=int ret_a_0D()) */
extern "C" void shim_24(void **in_ref, void **out_ref, const char *context) {
    E *_i0 = reinterpret_cast<E *>(in_ref[0]);
    E *_o0;
    ((D *)_i0)->ret_a();
    _o0 = _i0;
    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=char ret_b_0D()) */
extern "C" void shim_25(void **in_ref, void **out_ref, const char *context) {
    E *_i0 = reinterpret_cast<E *>(in_ref[0]);
    E *_o0;
    ((D *)_i0)->ret_b();
    _o0 = _i0;
    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=int ret_a_1C()) */
extern "C" void shim_26(void **in_ref, void **out_ref, const char *context) {
    E *_i0 = reinterpret_cast<E *>(in_ref[0]);
    E *_o0;
    ((C *)_i0)->ret_a();
    _o0 = _i0;
    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=char ret_b_1C()) */
extern "C" void shim_27(void **in_ref, void **out_ref, const char *context) {
    E *_i0 = reinterpret_cast<E *>(in_ref[0]);
    E *_o0;
    ((C *)_i0)->ret_b();
    _o0 = _i0;
    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) E::void b_func();) */
extern "C" void shim_28(void **in_ref, void **out_ref, const char *context) {
    E *_i0 = reinterpret_cast<E *>(in_ref[0]);
    E *_o0;
    _i0->b_func();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) E::E();) */
extern "C" void shim_29(void **in_ref, void **out_ref, const char *context) {
    E *_o0;
    _o0 = new E();
    
                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) E::~E();) */
extern "C" void shim_30(void **in_ref, void **out_ref, const char *context) {
    E *_i0 = reinterpret_cast<E *>(in_ref[0]);
    delete _i0;
    
                    
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
};

