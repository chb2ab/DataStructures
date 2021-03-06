// Crispin Bernier, chb2ab, lab05

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include "avltree.h"

using namespace std;

class hashTable {
 public:
  hashTable(double l, int si);			//Constructor
  ~hashTable();					//Destructor
  int getNextPrime(unsigned int n);
  bool checkprime(unsigned int p);
  void insert(string word);
  bool search(string s);

 private:
  vector< AvlTree > hashtable;
  double load;
  int size;
};

#endif
