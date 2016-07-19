// Crispin Bernier, chb2ab
// Code for heap.h and heap.cpp modified from the code written by Aaron Bloomfield

#include <iostream>
#include "heap.h"
using namespace std;

// default constructor
heap::heap() : heap_size(0) {
    cheap.push_back(NULL);
}

// builds a heap from an unsorted vector
heap::heap(vector<HuffmanNode*> vec) : heap_size(vec.size()) {
    cheap = vec;
    cheap.push_back(cheap[0]);
    cheap[0] = 0;
    for ( int i = heap_size/2; i > 0; i-- )
        percolateDown(i);
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(HuffmanNode *x) {
    // a vector push_back will resize as necessary
    cheap.push_back(x);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    HuffmanNode *x = cheap[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && ((*x) < (*cheap[hole/2])); hole /= 2 ){
        cheap[hole] = cheap[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    cheap[hole] = x;
}

HuffmanNode* heap::deleteMin() {
    // make sure the heap is not empty
    if ( heap_size == 0 )
        throw "deleteMin() called on empty heap";
    // save the value to be returned
    HuffmanNode *ret = cheap[1];
    // move the last inserted position into the root
    cheap[1] = cheap[heap_size--];
    // make sure the vector knows that there is one less element
    cheap.pop_back();
    // percolate the root down to the proper position
    percolateDown(1);
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    HuffmanNode *x = cheap[hole];
    // while there is a left child...
    while ( hole*2 <= heap_size ) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ( (child+1 <= heap_size) && ((*cheap[child+1]) < (*cheap[child])) )
            child++;
        // if the child is greater than the node...
        if ( (*x) > (*cheap[child]) ) {
            cheap[hole] = cheap[child]; // move child up
            hole = child;             // move hole down
        } else
            break;
    }
    // correct position found!  insert at that spot
    cheap[hole] = x;
}

HuffmanNode* heap::findMin() {
    if ( heap_size == 0 )
        throw "findMin() called on empty heap";
    return cheap[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(" << cheap[0] << ") ";
    for ( int i = 1; i <= heap_size; i++ ) {
        cout << cheap[i]->element;
        // next line from from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if ( isPow2 )
            cout << endl << "\t";
    }
    cout << endl;
}
