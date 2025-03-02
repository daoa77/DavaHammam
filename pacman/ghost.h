// ghost.h
#ifndef GHOST_H
#define GHOST_H

#include <iostream>
using namespace std;

class Ghost {
public:
    virtual void move() = 0;
    virtual ~Ghost();
};

class RedGhost : public Ghost {
public:
    void move() override;
};

class BlueGhost : public Ghost {
public:
    void move() override;
};

#endif