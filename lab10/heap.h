// Crispin Bernier, chb2ab
// Code for heap.h and heap.cpp modified from the code written by Aaron Bloomfield

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "HuffmanNode.h"
using namespace std;

class heap {
public:
    heap();
    heap(vector<HuffmanNode*> vec);
    ~heap();

    void insert(HuffmanNode *x);
    HuffmanNode* findMin();
    HuffmanNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();

private:
    vector<HuffmanNode*> cheap;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
