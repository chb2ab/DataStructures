#include <iostream>
#include <cstdlib>

using namespace std;

class Computer
{
public:
  Computer();
  ~Computer();
  int incs1(int x);
protected:
  int processorspeed;
  int graphics;
  int power;
};

Computer::Computer()
{
  processorspeed = 0;
  graphics = 0;
  power = 0;
}

Computer::~Computer(){
}

int Computer::incs1(int x){
graphics += x;
return graphics;
}

class Laptop
{
public:
  Laptop();
  int incs1(int x, int y);
  int getheadset();
  char keyboard;
  int headset;

protected:
  int touchpad;
  double cpu;
  //Computer internal;
};

Laptop::Laptop()
{
keyboard = 'a';
touchpad = 24;
cpu = 3.14;
headset = 12;
//Computer b;
//internal = b;
}

int Laptop::incs1(int x, int y){
int z = getheadset() + x + 6;
return z;
}

int Laptop::getheadset(){
return headset;
}

extern "C" int testes (int[], int, int);

int  main () {
    Laptop a;
    a.headset = 5;
    a.incs1(19,4);
    return 0;
}
