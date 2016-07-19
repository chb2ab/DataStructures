#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "HuffmanNode.h"

using namespace std;

int main (int argc, char **argv) {
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    ifstream file(argv[1], ifstream::binary);
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    HuffmanNode root;
    char buffer[256];
    while ( true ) {
        char first = file.get();
        if ( (first == '\n') || (first == '\r') )
            continue;
        char second = file.get();
        if ( (first == '-') && (second == '-') ) {
            file.getline(buffer, 255, '\n');
            break;
        }
        file.getline(buffer, 255, '\n');

        cout << "character '" << first << "' has prefix code '" << buffer << "'" << endl;
    }
    char bit;
    while ( (bit = file.get()) != '-' ) {
        if ( (bit != '0') && (bit != '1') )
            continue;
        cout << "read in bit '" << bit << "'" << endl;
    }
    file.close();
    return 0;
}
