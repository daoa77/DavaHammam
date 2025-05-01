#ifndef GHOSTTYPES_H
#define GHOSTTYPES_H

#include "Ghost.h"

class Blinky : public Ghost {
public:
    Blinky(int x, int y) : Ghost(x, y) {}
    char getSymbol() const override { return 'B'; } // Simbol untuk Blinky
};

class Pinky : public Ghost {
public:
    Pinky(int x, int y) : Ghost(x, y) {}
    char getSymbol() const override { return 'P'; } // Simbol untuk Pinky
};

class Inky : public Ghost {
public:
    Inky(int x, int y) : Ghost(x, y) {}
    char getSymbol() const override { return 'I'; } // Simbol untuk Inky
};

class Clyde : public Ghost {
public:
    Clyde(int x, int y) : Ghost(x, y) {}
    char getSymbol() const override { return 'C'; } // Simbol untuk Clyde
};

#endif