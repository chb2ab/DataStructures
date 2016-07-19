// Crispin Bernier, chb2ab, lab01, postfixCalculator.h, 9/15/14

#ifndef postfixCalculator_H
#define postfixCalculator_H

#include <iostream>
#include <stack>
using namespace std;

class postfixCalculator {
public:
    postfixCalculator();
    void addNumber(int x);
    void print();
    int getNumber();
    int add();
    int subtract();
    int multiply();
    int divide();
    int negate();
    void empty();
private:
    stack<int> st;
};

#endif
