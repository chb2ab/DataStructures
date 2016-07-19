// Crispin Bernier, chb2ab
#include <iostream>
#include <fstream>
#include <stdlib.h>
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
//Read in file
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    ifstream file(argv[1], ifstream::binary);
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
//Root will be the root of the decoding tree, current is used to create the nodes of the decoding tree
    HuffmanNode *root = new HuffmanNode();
    HuffmanNode *current = root;
    char buffer[256];
    while ( true ) {
//First stores the character
        char first = file.get();
        if ( (first == '\n') || (first == '\r') )
            continue;
        char second = file.get();
        if ( (first == '-') && (second == '-') ) {
            file.getline(buffer, 255, '\n');
            break;
        }
//buffer stores the prefix code
        file.getline(buffer, 255, '\n');
//prepare x to go through the prefix code one bit at a time
        int x = 0;
//current points to the root
        current = root;
//while we are still looking at the prefix code
        while (buffer[x] == '0' || buffer[x] == '1'){
//if we see a 0 and the left of current points to NULL, create a new node to the left and set current to that node. Otherwise just set current to its left pointer. 
            if (buffer[x] == '0'){
                if (current->left == NULL){
                    HuffmanNode *node = new HuffmanNode();
                    current->left = node;
                }
                current = current->left;
            }
//if we see a 1 and the right of current points to NULL, create a new node to the right and set current to that node. Otherwise just set current to its right pointer.
            else if (buffer[x] == '1'){
                if (current->right == NULL){
                    HuffmanNode *node = new HuffmanNode();
                    current->right = node;
                }
                current = current->right;
            }
//go to the next bit in the prefix code
            x++;
        }
//after the loop, current points to the HuffmanNode leaf corresponding to the character and prefix code read in, set this leaf to have an element of the character first and prefix code read in by buffer
        current->element = first;
        current->code = buffer;
    }
//prepare to decompress, current starts at the root, bit holds the next bit
    current = root;
    char bit;
    while ( (bit = file.get()) != '-' ) {
        if ( (bit != '0') && (bit != '1') )
            continue;
//if the next bit is 0, go to the left, if it is 1 go to the right
        if (bit == '0'){
            current = current->left;
        }
        if (bit == '1'){
            current = current->right;
        }
//if the element at the current node is not NULL, it is a leaf so we print its element and reset the current to root.
        char a = NULL;
        if (current->element != a){
            cout << current->element;
            current = root;
        }
    }
    file.close();
    cout << endl;
//delete all the dynamically allocated HuffmanNodes
    current = root;
    deletetree(current);
    return 0;
}
