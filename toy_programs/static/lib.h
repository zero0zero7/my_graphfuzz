#include <iostream>
using namespace std;


class A {
public:
   A() {_balance = 0.0;}
   A(double d) {_balance = d;}   // Constructor.
   double retbal() {return _balance;}
   static double GetBalanceFrom(A* a) {return a->retbal();}   // Obtain balance.
   void static static_print() {cout << "static print" << endl;}
protected:
    void SetBalance(double x) {_balance = x;}
    void static static_prot() {cout << "static protected" << endl;}
private:
    double _balance;
};
// 5 public methods


// default would be private
class ClassB: A{
public:
    ClassB() {money = 0;}
    static int b_id() {return id;}
private:
    int money;
    static int id;
};
// 2 public methods -- construc, b_id
int ClassB::id;

class ClassC: public A{
public:
    ClassC() {money = 0;}
protected:
    int c_prot_get() {return money;}
private:
    int money;
};
// 4 public methods -- construc, retbal, GetBalanceFrom, static_print


class ClassE:  protected ClassC {
public:
    ClassE() {id = 0;}
    void static static_e() {cout << "static e" << endl;}
private:
    int id;
};
// 2 public methods -- construc, static_e






// default would be public
struct W: A{
public:
    W() {money = 0;}
    static int w_public_get() {return money;}
protected:
    int w_prot_get() {return money;}
private:
    static int money;
};
// 5 public methods -- construc, w_public_get, GetBalanceFrom, retbal, static_print
int W::money;


struct ClassX: private A{
public:
    ClassX() {money = 0;}
protected:
    int x_prot_get() {return money;}
    void static_x() {cout << "static_x" << endl;}
private:
    int money;
};
// 1 public methods -- construc


struct Y:  protected W {
public:
    Y() {id = 0;}
    void static static_y() {cout << "static y" << endl;}
private:
    int id;
};
// 2 public methods -- construc, static_y
