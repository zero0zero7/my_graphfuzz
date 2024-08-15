#include<unistd.h>
#include <iostream>
using namespace std;


/*
   A (has a virtual method)
 / |  \      
Z  B     C  
| /    /   
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


class Z : public A {
public:
    Z() {num=0;}
    void z_func() {}
private:
    int num;
};


// Child of B
// should inherit public methods from B (which includes A's)
class D : public B, public Z {
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



int main() {
    E* e = new E();
    A* a = (A*)(B*)e;
    return 0;
}
