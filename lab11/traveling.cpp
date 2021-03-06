// Crispin Bernier, chb2ab
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance (MiddleEarth &me, string start, vector<string> dests);
void printRoute (string start, vector<string> dests);

/** @brief Does a brute force traveling salesman calculation.
 *
 * @return 0.
 * @param argc should be 6.
 * @param argv Gets the height, width, number of cities, seed, and itenerary size from command line parameters.
 */
int main (int argc, char **argv) {
/** 
 * Generate the world given the command line parameters and store this world in me.
 */
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed); /**< The generated world */
    vector<string> dests = me.getItinerary(cities_to_visit); /**< The generated itinerary */
    string start = dests[0]; /**< The first element in the itinerary is the starting position, which is removed */
    dests.erase(dests.begin());
    vector<string> final = dests; /**< final will hold the solution to the traveling salesman problem */
    float min = computeDistance(me, start, dests); /**< min will hold the total distance of the solution to the traveling salesman problem */
    float tdist; /**< tdist will hold the total distance of a given permutation of the itinerary to be compared with min */
/** 
 * Permutate through all combinations of the itinerary, if a given permuation has a distance shorter than min, set that permutation as the new min.
 */
    sort(dests.begin(), dests.end());
    while ( next_permutation(dests.begin(), dests.end()) ){
        tdist = computeDistance(me, start, dests);
        if (tdist < min){
            final = dests;
            min = tdist;
        }
    }
/** 
 * Print out the value and itinerary of the calculated shortest distance.
 */
    cout << "Minimum path has distance " << min << ": ";
    printRoute(start, final);
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parmater, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
/** @brief Computes the total distance of a given path.
 *
 * @return Returns the sum of the distances as a float.
 * @param me The generated world.
 * @param start A string containing the starting location.
 * @param dests A vector of all the destinations to travel to in order.
 */
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
    float sum = 0.0;
    sum += me.getDistance(start, dests[0]);
    for (int x = 0; x < dests.size()-1; x++)
        sum += me.getDistance(dests[x], dests[x+1]);
    sum += me.getDistance(dests[dests.size()-1], start);
    return sum;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.  The output should be of the form:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
/** @brief Prints the route for a given starting position and vector of destinations.
 *
 * @param start The starting position.
 * @param dests A vector of the destinations to print in order.
 */
void printRoute (string start, vector<string> dests) {
    cout << start << " -> ";
    for (int x = 0; x < dests.size(); x++)
        cout << dests[x] << " -> ";
    cout << start << endl;
}
