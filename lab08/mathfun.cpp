// crispin bernier, chb2ab

#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" int product (int, int);
extern "C" int power (int, int);
extern "C" int umm ();

int  main () {
    int  x, y, pro, pow;
    cout << sizeof(float) << endl;
    cout << sizeof(float*) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(float*) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(char*) << endl;
    cout << sizeof(double) << endl;
    cout << sizeof(double*) << endl;
    cout << "Enter x:  ";
    cin >> x;

    cout << "Enter y:  ";
    cin >> y;

    pro = product(x, y);
    cout << x << "*" << y << "= " << pro << endl;

    pow = power(x, y);
    cout << x << "^" << y << "= " << pow << endl;
    int z = umm();
    cout << z << endl;
    return 0;
}
