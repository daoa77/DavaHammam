#ifndef GHOST_H
#define GHOST_H

#include "GhostState.h"
#include <memory>

class Ghost {
protected:
    int x, y; // Posisi saat ini
    int prevX, prevY; // Posisi sebelumnya
    int startX, startY; // Posisi awal Ghost
    std::shared_ptr<GhostState> state;
public:
    Ghost(int x, int y);
    virtual void move(int pacX, int pacY);
    void changeState(std::shared_ptr<GhostState> newState);
    int getX() const;
    int getY() const;
    int getPrevX() const; // Getter untuk posisi sebelumnya X
    int getPrevY() const; // Getter untuk posisi sebelumnya Y
    int getStartX() const; // Getter untuk posisi awal X
    int getStartY() const; // Getter untuk posisi awal Y
    virtual char getSymbol() const;
    virtual const char* getStateName() const;
    virtual ~Ghost() = default;
};

#endif