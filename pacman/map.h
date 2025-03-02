#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
using namespace std;

class Map {
private:
    vector<string> layout;
public:
    Map();
    void draw();
};

#endif