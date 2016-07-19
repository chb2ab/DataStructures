//Crispin Bernier prelab4.cpp chb2ab

#include <iostream>
#include <cmath>
using namespace std;

void sizeOfTest() {
int a;
unsigned int b;
float c;
double d;
char e;
bool f;
int* g;
char* h;
double* i;

cout << "-Size Of-" << endl;
cout << "int " << sizeof(a) << endl;
cout << "unsigned int " << sizeof(b) << endl;
cout << "float " << sizeof(c) << endl;
cout << "double " << sizeof(d) << endl;
cout << "char " << sizeof(e) << endl;
cout << "bool " << sizeof(f) << endl;
cout << "int* " << sizeof(g) << endl;
cout << "char* " << sizeof(h) << endl;
cout << "double* " << sizeof(i) << endl;
}

void outputBinary(unsigned int a) {
int y = 1;
int x = 0;
int z = 31;
int spacer = 0;
while (z>=0){
while (x<z) {
y = y * 2;
x++;
}
cout << a/y;
if (a/y){
    a = a-y;
}
y = 1;
x = 0;
spacer++;
if (spacer == 4){
cout << " ";
spacer = 0;
}
z--;
}
cout << "" << endl;
}

void overflow() {
unsigned int x = 0xFFFFFFFF;
cout << "max: " << x << endl;
cout << "max+1: " << x+1 << endl;
cout << "The max value for an unsigned int plus 1 goes to the min value of an unsigned int, which ='s zero. This happens because the max size of an unsigned int is 4 bytes, which is 32 bits, which is represented in binary as 11111... with 32 1's. Adding 1 to this gives 10000... with 32 0's, but this requires 33 bits to represent, which is more than is allowed by an unsigned int, so the 33rd bit is cut off leaving just 0000... with 32 zeros which ='s 0. Thus, max unsigned int + 1 = 0." << endl;
}

int main() {
sizeOfTest();
int x;
cout << "x: ";
cin >> x;
outputBinary(x);
overflow();
return 0;
}
