// crispin bernier, chb2ab

#include <iostream>
#include <cstdlib>
#include "timer.h"

using namespace std;

extern "C" int threexplusone(int);

int  main () {
    int x;
    int n;
    timer t;
    cout << "Choose an x: " << endl;
    cin >> x;
    cout << "Choose an n: " << endl;
    cin >> n;
    t.start();
    for (int x = 0; x < n; x++){
        threexplusone(x);
    }
    t.stop();
    cout << "threeexplusone(" << x << ") = " << threexplusone(x) << endl;
    double y = t.getTime()/n;
    cout << "average time per run = " << y << " seconds" << endl;
    return 0;
}
