#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

class A {
    public:
    virtual void print(){
        cout << "A" << endl;
    }
    virtual char give(int x){
        char y = x+96;
        cout << y << endl;
        return y;
    }

};

class B : public A {
    public:
    virtual void print(){
        cout << "B" << endl;
    }
    virtual char give(int x){
        char y = x;
        cout << y << endl;
        return y;
    }
};

class C : public B {
    public:
    virtual void print(){
        cout << "C" << endl;
    }
    virtual char give(int x){
        char y = x+48;
        cout << y << endl;
        return y;
    }
};

extern "C" int threexplusone (int);

int  main () {
    int which = rand()%3;
    A *bar;
    switch ( which ){
    case 0 :
        bar = new A();
        break;
    case 1 :
        bar = new B();
        break;
    case 2 :
        bar = new C();
        break;
    }
    bar->print();
    char b = bar->give(5);
    return 0;
}
