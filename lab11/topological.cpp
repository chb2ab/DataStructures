// Crispin Bernier, chb2ab
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>
using namespace std;

/** @brief Prints a valid topological sort of a map input to the screen.
 *
 * @return 0.
 * @param argc should be 2.
 * @param argv the name of the file with the map.
 */
int main (int argc, char **argv) {
/** 
 * Check for the command-line paramater input file and prepare to read from that file.
 */
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    ifstream file(argv[1], ifstream::binary);
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    vector<string> vert;	/**< A vector of strings containing all the vertices */
    list<string> alist[100];	/**< An array of lists of strings containing all the vertices that point to a given vertice */
    string first;		/**< In the file the first string is the starting vertice */
    string second;		/**< In the file the second string is the end vertice */
/** 
 * Read in the first and second strings in the file.
 */
    file >> first;
    file >> second;
/** 
 * Read in all the path entries in the file and generate the vector of vertices in vert, and the list of paths for each vertice in alist.
 */
    while (first != "0" && second != "0"){
        int firstloc = -1;
        int secondloc = -1;
        for(int x = 0; x < vert.size(); x++){
            if (vert[x] == first)
                firstloc = x;
            if (vert[x] == second)
                secondloc = x;
        }
        if (firstloc == -1){
            vert.push_back(first);
            firstloc = vert.size()-1;
        }
        if (secondloc == -1){
            vert.push_back(second);
            secondloc = vert.size()-1;
        }
        alist[secondloc].push_back(first);
        file >> first;
        file >> second;
    }
    file.close();

    int counter = 0;	/**< Counter iterates through the size of vert */
/** 
 * Perform the topological sort on the vertices.
 */
    while (counter < vert.size()){
    string v = "";
    int y = 0;
/** 
 * Searches the vertices for one with 0 paths to it, if none are found the topological sort is finished.
 */
    while (y < vert.size()){
        if (alist[y].size() == 0){
            v = vert[y];
            alist[y].push_back("0 0"); //Insert a placeholder
            y = vert.size()+1;
        }
        y++;
    }
    if (v == ""){
        counter = vert.size()+1; //Cycle found
    }
/** 
 * Prints the vertice and erases its paths from the all the lists, repeat untill all the vertices have been hit.
 */
    else {
        cout << v << " ";
        for (int x = 0; x < vert.size(); x++)
            alist[x].remove(v);
    }
    counter++;
    }
    cout << endl;
    return 0;
}
