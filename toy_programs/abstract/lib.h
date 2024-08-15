#include <iostream>
#include <string>
using namespace std;

/*
! means abstract
    !A
  /   \       
!B     C     
|  \  /       
D   !E (E has no issue like in /diamond because E is an abstract class)         
*/

class A {
public:
    A() {money = 0;}
    int get_money() {return money;}
    void set_money(int x) {money = x;}
    virtual char ret_a() {return 'a';}
    static char non_virt() {return 'd';}
    virtual char ret_b() =0;
private:
    int money;
};

// Child of A
// also abstract
class B : public A {
public:
    B() {money=0;}
    virtual void b_func() {}
    char ret_a() {return 'a';}
    static char non_virt() {return 'e';}
private:
    int money;
};

// Child of A
class C : public A {
public:
    C() {money=0;}
    // override ret_b
    char ret_b() {return 'b';}
private:
    int money;
};

// Child of B
class D : public B {
public:
    D() {money=3;}
    // override ret_b
    char ret_b() {return 'd';}
    static char non_virt() {return 'f';}
private:
    int money;
};


class E : public B, public C {
public:
    E() {money = 20;}
private:
    int money;
};
