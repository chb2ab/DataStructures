#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <string>
#include "heap.h"
#include "HuffmanNode.h"

using namespace std;
//function for deleting the dynamically allocated tree
void deletetree(HuffmanNode *cur){
    if (cur->left != NULL)
        deletetree(cur->left);
    if (cur->right != NULL)
        deletetree(cur->right);
    delete cur;
}

int main (int argc, char **argv) {
cout << argv[1] << endl;
//Read in file
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    FILE *fp = fopen(argv[1], "r");
    if ( fp == NULL ) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }

    vector<HuffmanNode*> chars;
    char g;
    bool in;
    int val;
    //Read in one character at a time, add that character to the vector of HuffmanNode* by either creating a new node or incrementing the frequency of a preexisting node
    while ( (g = fgetc(fp)) != EOF && (val = g) >= 0x20 && (val = g) <= 0x7e){
        in = false;
        int x = 0;
        while ( x < chars.size() && in == false) {
            if ((chars[x])->element == g){
                (chars[x])->frequency++;
                in = true;
            }
            x++;
        }
        if (in == false){
            HuffmanNode *y = new HuffmanNode(g);
            chars.push_back(y);
            }
    }
    //Insert the vector of node pointers to the heap
    heap theheap;
    for (int x = 0; x < chars.size(); x++){
        theheap.insert(chars[x]);
    }
    //Build the huffman tree. The root of the tree will be the only thing stored in theheap afterwards.
    int sz = theheap.size();
    for (int x = 1; x < sz; x++){
        HuffmanNode *y = new HuffmanNode();
        (*y).left = theheap.deleteMin();
        (*y).right = theheap.deleteMin();
        (*y).frequency = (*y).left->frequency + (*y).right->frequency;
        theheap.insert(y);
    }
    //Print the huffman tree using the printer method in the HuffmanNode class, which takes in an empty string.
    string str = "";
    theheap.findMin()->printer(str);
    cout << "----------------------------------------" << endl;
    //Reread the file
    rewind(fp);
    //ascicount will count the number of characters in the file, which multiplied by 8 is the number of bits. comprcount will count the number of bits in the encoded version.
    //The bit encoding will also be printed to screen with each ascii character seperated by a space and each word seperated by a new line. 
    int ascicount = 0;
    int comprcount = 0;
    while ( (g = fgetc(fp)) != EOF && (val = g) >= 0x20 && (val = g) <= 0x7e){
    ascicount++;
        for (int x = 0; x < chars.size(); x++){
            if (g == chars[x]->element){
                comprcount += chars[x]->code.size();
                cout << chars[x]->code << " ";
            }
        }
        if (g == 0x20)
            cout << endl; 
    }
    cout << endl;
    fclose(fp);
    //encost will hold the encoding cost of the huffman tree
    double encost = 0;
    for (int x = 0; x<chars.size(); x++){
        encost+=(double (chars[x]->frequency))*(double (chars[x]->code.size()))/(double (ascicount));
    }
    //Print the results
    cout << "----------------------------------------" << endl;
    cout << "there were " << ascicount << " characters and " << ascicount*8 << " bits in the original file" << endl;
    cout << "there were " << comprcount << " bits in the compressed file" << endl;
    double ratio = (double (ascicount*8))/(double (comprcount));
    cout << "the compression ratio is " << ratio << endl;
    cout << "the encoding cost is " << encost << endl;
    //Delete the huffmanNodes
    while (!theheap.isEmpty()){
        deletetree(theheap.findMin());
        theheap.deleteMin();
    }
    chars.clear();
    return 0;
}
