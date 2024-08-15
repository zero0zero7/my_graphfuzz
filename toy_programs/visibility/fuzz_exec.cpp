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



template <class B, class D, class SubB> void __attribute__((visibility ("default"))) cast_helper(void** in, void** out) {
    D* d = reinterpret_cast<D*>(in[0]);
    SubB* i = (SubB*)d;
    B* b = (B*)i;
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
#define BASE2DERIVED(Base, Derived,SubBase) { \
    unsigned b_id = name_id[#Base], \
        d_id = name_id[#Derived]; \
    /* remembers the instantiated cast */ \
    (*cast_map)[b_id][d_id] = cast_helper<Base,Derived,SubBase>; \
}
#include "new_classpairs.inc"
#undef BASE2DERIVED
}


/* CPPScope(name=(auto) A::A();) */
extern "C" void shim_0(void **in_ref, void **out_ref, const char *context) {
    A *_o0;
    _o0 = new A();
    
                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) A::A(double d);) */
extern "C" void shim_1(void **in_ref, void **out_ref, const char *context) {
    double _a0;
    memcpy(&_a0, context + 0, sizeof(double));
    A *_o0;
    _o0 = new A(_a0);
    
                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) A::double GetBalance();) */
extern "C" void shim_2(void **in_ref, void **out_ref, const char *context) {
    A *_i0 = reinterpret_cast<A *>(in_ref[0]);
    A *_o0;
    _i0->GetBalance();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) A::double GetBalanceFrom(A * a);) */
extern "C" void shim_3(void **in_ref, void **out_ref, const char *context) {
    A *_i0 = reinterpret_cast<A *>(in_ref[0]);
    A *_i1 = reinterpret_cast<A *>(in_ref[1]);
    A *_o0;
    A *_o1;
    _i0->GetBalanceFrom(_i1);
    _o0 = _i0;
    _o1 = _i1;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) A::~A();) */
extern "C" void shim_4(void **in_ref, void **out_ref, const char *context) {
    A *_i0 = reinterpret_cast<A *>(in_ref[0]);
    delete _i0;
    
                    
}


/* CPPScope(name=(auto) ClassB::int b_public_get();) */
extern "C" void shim_5(void **in_ref, void **out_ref, const char *context) {
    ClassB *_i0 = reinterpret_cast<ClassB *>(in_ref[0]);
    ClassB *_o0;
    _i0->b_public_get();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) ClassB::ClassB();) */
extern "C" void shim_6(void **in_ref, void **out_ref, const char *context) {
    ClassB *_o0;
    _o0 = new ClassB();
    
                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) ClassB::~ClassB();) */
extern "C" void shim_7(void **in_ref, void **out_ref, const char *context) {
    ClassB *_i0 = reinterpret_cast<ClassB *>(in_ref[0]);
    delete _i0;
    
                    
}


/* CPPScope(name=(auto) ClassC::ClassC();) */
extern "C" void shim_8(void **in_ref, void **out_ref, const char *context) {
    ClassC *_o0;
    _o0 = new ClassC();
    
                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) ClassC::double GetBalance();) */
extern "C" void shim_9(void **in_ref, void **out_ref, const char *context) {
    ClassC *_i0 = reinterpret_cast<ClassC *>(in_ref[0]);
    ClassC *_o0;
    _i0->GetBalance();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) ClassC::double GetBalanceFrom(A * a);) */
extern "C" void shim_10(void **in_ref, void **out_ref, const char *context) {
    ClassC *_i0 = reinterpret_cast<ClassC *>(in_ref[0]);
    A *_i1 = reinterpret_cast<A *>(in_ref[1]);
    ClassC *_o0;
    A *_o1;
    _i0->GetBalanceFrom(_i1);
    _o0 = _i0;
    _o1 = _i1;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) ClassC::~ClassC();) */
extern "C" void shim_11(void **in_ref, void **out_ref, const char *context) {
    ClassC *_i0 = reinterpret_cast<ClassC *>(in_ref[0]);
    delete _i0;
    
                    
}


/* CPPScope(name=(auto) ClassE::ClassE();) */
extern "C" void shim_12(void **in_ref, void **out_ref, const char *context) {
    ClassE *_o0;
    _o0 = new ClassE();
    
                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) ClassE::~ClassE();) */
extern "C" void shim_13(void **in_ref, void **out_ref, const char *context) {
    ClassE *_i0 = reinterpret_cast<ClassE *>(in_ref[0]);
    delete _i0;
    
                    
}


/* CPPScope(name=(auto) ClassX::ClassX();) */
extern "C" void shim_14(void **in_ref, void **out_ref, const char *context) {
    ClassX *_o0;
    _o0 = new ClassX();
    
                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) ClassX::~ClassX();) */
extern "C" void shim_15(void **in_ref, void **out_ref, const char *context) {
    ClassX *_i0 = reinterpret_cast<ClassX *>(in_ref[0]);
    delete _i0;
    
                    
}


/* CPPScope(name=(auto) W::double GetBalance();) */
extern "C" void shim_16(void **in_ref, void **out_ref, const char *context) {
    W *_i0 = reinterpret_cast<W *>(in_ref[0]);
    W *_o0;
    _i0->GetBalance();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) W::double GetBalanceFrom(A * a);) */
extern "C" void shim_17(void **in_ref, void **out_ref, const char *context) {
    W *_i0 = reinterpret_cast<W *>(in_ref[0]);
    A *_i1 = reinterpret_cast<A *>(in_ref[1]);
    W *_o0;
    A *_o1;
    _i0->GetBalanceFrom(_i1);
    _o0 = _i0;
    _o1 = _i1;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
    out_ref[1] = reinterpret_cast<void *>(_o1);
}


/* CPPScope(name=(auto) W::W();) */
extern "C" void shim_18(void **in_ref, void **out_ref, const char *context) {
    W *_o0;
    _o0 = new W();
    
                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) W::int w_public_get();) */
extern "C" void shim_19(void **in_ref, void **out_ref, const char *context) {
    W *_i0 = reinterpret_cast<W *>(in_ref[0]);
    W *_o0;
    _i0->w_public_get();
    _o0 = _i0;
                        
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) W::~W();) */
extern "C" void shim_20(void **in_ref, void **out_ref, const char *context) {
    W *_i0 = reinterpret_cast<W *>(in_ref[0]);
    delete _i0;
    
                    
}


/* CPPScope(name=(auto) Y::Y();) */
extern "C" void shim_21(void **in_ref, void **out_ref, const char *context) {
    Y *_o0;
    _o0 = new Y();
    
                    
    out_ref[0] = reinterpret_cast<void *>(_o0);
}


/* CPPScope(name=(auto) Y::~Y();) */
extern "C" void shim_22(void **in_ref, void **out_ref, const char *context) {
    Y *_i0 = reinterpret_cast<Y *>(in_ref[0]);
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
};

