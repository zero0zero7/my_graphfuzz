#include <cstring>
#include<unistd.h>
#include <iostream>



class A {
public:
    A() {}
    void mset(char chr, int n) {memset(buffer, chr, n);}
    void fr() {free(buffer);}
    void mall_free(int n){
        doub_ptr = (double*)malloc(sizeof(double)*n);
        free(doub_ptr);
    }
    virtual char* get_buffer() {return buffer;}
    void set_buffer(int idx, char chr) {buffer[idx] = chr;}
    static char ret_a() {return 'a';}
    virtual ~A() {std::cout << "calling A destr" << std::endl;}
private:
    char* buffer;
    double* doub_ptr;
};

class B : public A {
public:
    B() {b = 2;}
private:
    int b;
};

class C : public B {
public:
    C() {c = 4.0;}
    float get_c() {return c;}
private:
    float c;
};
