// Crispin Bernier, chb2ab

#include "HuffmanNode.h"
#include <iostream>
#include <string>

//Default constructor
HuffmanNode::HuffmanNode() : element(NULL), frequency(1), code(""), left(NULL), right(NULL) {
}
//Constructor given character
HuffmanNode::HuffmanNode(char z) : frequency(1), code(""), left(NULL), right(NULL) {
element = z;
}
//Destructor doesn't need to do much
HuffmanNode::~HuffmanNode() {
}
//Prints out the huffman tree in the form "char code" for each char
void HuffmanNode::printer(string str) {
    if (left == NULL && right == NULL){
        cout << element << " " << str << endl;
        code = str;
    }
    else {
        str.push_back('0');
        left->printer(str);
        str.erase(str.end()-1, str.end());
        str.push_back('1');
        right->printer(str);
        str.erase(str.end()-1, str.end());
    }
}
//Less then operator comparing frequency
const bool HuffmanNode::operator<(const HuffmanNode n) {
    return frequency < n.frequency;
}
//greater then operator comparing frequency
const bool HuffmanNode::operator>(const HuffmanNode n) {
    return frequency > n.frequency;
}
