// Crispin Bernier, chb2ab, lab01, testPostfixCalc.cpp, 9/15/14

#include <iostream>

using namespace std;

#include "postfixCalculator.h"

using namespace std;

int main () {
postfixCalculator test;
cout << "TEST ADD" << endl;
test = postfixCalculator();
test.addNumber(1); test.addNumber(2); test.addNumber(3); test.addNumber(4); test.addNumber(5); test.add(); test.add(); test.add(); test.add();
test.print();
test.empty();
cout << "TEST SUBTRACT" << endl;
test.addNumber(20); test.addNumber(10); test.subtract(); test.addNumber(-3); test.addNumber(10); test.subtract(); test.subtract(); test.addNumber(2); test.subtract();
test.print();
test.empty();
cout << "TEST MULTIPLY" << endl;
test.addNumber(-1); test.addNumber(-2); test.addNumber(-5); test.addNumber(3); test.multiply(); test.addNumber(2); test.addNumber(-2); test.multiply(); test.multiply(); test.multiply(); test.multiply();
test.print();
test.empty();
cout << "TEST DIVIDE" << endl;
test.addNumber(-1512); test.addNumber(-12); test.addNumber(-2); test.divide(); test.divide(); test.addNumber(-2); test.divide(); test.addNumber(3); test.divide();
test.print();
test.empty();
cout<< "TEST NEGATION" << endl;
test.addNumber(-1); test.negate(); test.negate(); test.negate();
test.print();
test.empty();

return 0;
}
