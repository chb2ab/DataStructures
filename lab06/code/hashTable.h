// Crispin Bernier, chb2ab, lab05

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

class hashtable {
 public:
  hashtable(double l, int si);			//Constructor
  int getNextPrime(unsigned int n);
  bool checkprime(unsigned int p);
  void insert(string word);
  bool search(string s);

 private:
  vector< string > htable;
  double load;
  int size;
  int off;
};

#endif
