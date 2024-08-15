#include <iostream>
using namespace std;


class A {
public:
   A() {_balance = 0.0;}
   A(double d) {_balance = d;}   // Constructor.
   double GetBalance() {return _balance;}   // Obtain balance.
   double GetBalanceFrom(A* a) {return a->GetBalance();}   // Obtain balance.
   virtual ~A() {}
protected:
    void SetBalance(double x) {_balance = x;}
private:
    double _balance;
};
// 3 public methods


// default would be private
class ClassB: A{
public:
    ClassB() {money = 0;}
    int b_public_get() {return money;}
private:
    int money;
};
// 2 public methods -- construc, b_public_get


class ClassC: public A{
public:
    ClassC() {money = 0;}
protected:
    int c_prot_get() {return money;}
private:
    int money;
};
// 2 public methods -- construc, GetBalance


class ClassE:  protected ClassC {
public:
    ClassE() {id = 0;}
private:
    int id;
};
// 1 public methods -- construc






// default would be public
struct W: A{
public:
    W() {money = 0;}
    int w_public_get() {return money;}
protected:
    int w_prot_get() {return money;}
private:
    int money;
};
// 3 public methods -- construc, w_public_get, GetBalance


struct ClassX: private A{
public:
    ClassX() {money = 0;}
protected:
    int x_prot_get() {return money;}
private:
    int money;
};
// 1 public methods -- construc


struct Y:  protected W {
public:
    Y() {id = 0;}
private:
    int id;
};
// 1 public methods -- construc
