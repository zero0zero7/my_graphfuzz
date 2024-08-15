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


/* CPPScope(name=(auto) C::C();) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    C *_o0;
    _o0 = new C();
    
                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) C::int get_money();) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    C *_i0 = reinterpret_cast<C *>(in_ref[0]);
    C *_o0;
    _i0->get_money();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) C::char ret_a();) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    C *_i0 = reinterpret_cast<C *>(in_ref[0]);
    C *_o0;
    _i0->ret_a();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) C::char ret_b();) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    C *_i0 = reinterpret_cast<C *>(in_ref[0]);
    C *_o0;
    _i0->ret_b();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) C::void set_money(int x);) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    C *_i0 = reinterpret_cast<C *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    C *_o0;
    _i0->set_money(_a0);
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) C::char A::non_virt();) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    C *_i0 = reinterpret_cast<C *>(in_ref[0]);
    C *_o0;
    _i0->A::non_virt();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) C::~C();) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    C *_i0 = reinterpret_cast<C *>(in_ref[0]);
    delete _i0;
    
                    
}


/* CPPScope(name=(auto) D::void b_func();) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    D *_i0 = reinterpret_cast<D *>(in_ref[0]);
    D *_o0;
    _i0->b_func();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) D::D();) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    D *_o0;
    _o0 = new D();
    
                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) D::int get_money();) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    D *_i0 = reinterpret_cast<D *>(in_ref[0]);
    D *_o0;
    _i0->get_money();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) D::char ret_a();) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    D *_i0 = reinterpret_cast<D *>(in_ref[0]);
    D *_o0;
    _i0->ret_a();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) D::char ret_b();) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    D *_i0 = reinterpret_cast<D *>(in_ref[0]);
    D *_o0;
    _i0->ret_b();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) D::void set_money(int x);) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    D *_i0 = reinterpret_cast<D *>(in_ref[0]);
    int _a0;
    memcpy(&_a0, context + 0, sizeof(int));
    D *_o0;
    _i0->set_money(_a0);
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) D::char D::non_virt();) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    D *_i0 = reinterpret_cast<D *>(in_ref[0]);
    D *_o0;
    _i0->D::non_virt();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) D::~D();) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    D *_i0 = reinterpret_cast<D *>(in_ref[0]);
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
};

