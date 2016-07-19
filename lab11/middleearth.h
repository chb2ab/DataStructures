#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

class MiddleEarth {
private:
    int num_city_names,/**< The number of possible cities, which is 40 */ xsize,/**< the width of the world */ ysize;	/**< the height of the world */
    vector<float> xpos,/**< vector of the x coordinates of the cities */ ypos;	/**< vector of the y coordinates of the cities */
    vector<string> cities;	/**< The actual number of cities in the world */
    float *distances;	/**< array of the distances between cities */
    map<string, int> indices;	/**< Hash table with strings as the keys and integers as the values */

public:
    MiddleEarth (int xsize, int ysize, int numcities, int seed);
    ~MiddleEarth();
    void print();
    void printTable();
    float getDistance (string city1, string city2);
    vector<string> getItinerary(unsigned int length);
};

#endif
