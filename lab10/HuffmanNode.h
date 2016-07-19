// Crispin Bernier, chb2ab

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <string>
using namespace std;

class HuffmanNode {
    public:
    HuffmanNode();
    HuffmanNode(char z);
    ~HuffmanNode();
    void printer(string str);
    const bool operator<(const HuffmanNode n);
    const bool operator>(const HuffmanNode n);
    char element;
    int  frequency;
    string code;
    HuffmanNode *left;
    HuffmanNode *right;
};

#endif
