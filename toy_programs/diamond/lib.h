#include<unistd.h>
#include <iostream>
using namespace std;


/*
   A (has a virtual method)
 /   \      
B     C  
|     /   
D    /  
  \ /
   E (no virtual inheritance)
*/

class A {
public:
    A() {num = 0;}
    // int get_num() {return num;}
    virtual int get_num() {return num;}
    // void set_num(int x) {num = x;}
    static char ret_a() {return 'a';}
    char ret_b();
//    char ret_b() {return 'b';}
    virtual ~A() {}
private:
    int num;
};

// Child of A
// should inherit public methods from A
class B : public A {
public:
    B() {num=0;}
    void b_func() {}
private:
    int num;
};

// Child of A
// should inherit public methods from A
class C : public A {
public:
    C() {num=0;}
    // override ret_a
    int ret_a() {return 8;}
private:
    int num;
};

// Child of B
// should inherit public methods from B (which includes A's)
class D : public B {
public:
    D() {num=3;}
    // override ret_a
    int ret_a() {return 9;}
private:
    int num;
};


class E : public D, public C {
public:
    E() {num = 8*9;}
private:
    int num;
};



// re-implement method in A, abort if called by derived class
char A::ret_b() {
    D* casted1 = dynamic_cast<D*>(this);
    if (casted1 != nullptr) {
        abort();
    }
    B* casted2 = dynamic_cast<B*>(this);
    if (casted2 != nullptr) {
        abort();
    }
    C* casted3 = dynamic_cast<C*>(this);
    if (casted3 != nullptr) {
        abort();
    }
    E* casted4 = dynamic_cast<E*>(this);
    if (casted4 != nullptr) {
        abort();
    }
    return 'b';
}

