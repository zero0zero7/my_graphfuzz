#include<unistd.h>
#include <iostream>
using namespace std;


/*
            A
  /     /        \       \
B      C      virt W    virt X
|                 \     /
D                    Y
*/

class A {
public:
    A() {money = 0;}
    // int get_money() {return money;}
    virtual int get_money() {return money;}
    void set_money(int x) {money = x;}
    static char ret_a() {return 'a';}
    char ret_b();
//    char ret_b() {return 'b';}
    virtual ~A() {}
private:
    int money;
};

// Child of A
// should inherit public methods from A
class B : public A {
public:
    B() {money=0;}
    void b_func() {}
private:
    int money;
};

// Child of A
// should inherit public methods from A
class C : public A {
public:
    C() {money=0;}
    // override ret_a
    int ret_a() {return 8;}
private:
    int money;
};

// Child of B
// should inherit public methods from B (which includes A's)
class D : public B {
public:
    D() {money=3;}
    // override ret_a
    int ret_a() {return 9;}
private:
    int money;
};


// should inherit public methods from A
class W : virtual public A {
public:
    W() {money = 8;}
private:
    int money;
};

// should inherit public methods from A
class X : virtual public A {
public:
    X() {money = 9;}
private:
    int money;
};

// no need to manually disambiguate (unlike E)
class Y : public W, public X {
public:
    Y() {money = 8*9;}
private:
    int money;
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
    Y* casted4 = dynamic_cast<Y*>(this);
    if (casted4 != nullptr) {
        abort();
    }
    X* casted5 = dynamic_cast<X*>(this);
    if (casted5 != nullptr) {
        abort();
    }
    W* casted6 = dynamic_cast<W*>(this);
    if (casted6 != nullptr) {
        abort();
    }
    return 'b';
}

