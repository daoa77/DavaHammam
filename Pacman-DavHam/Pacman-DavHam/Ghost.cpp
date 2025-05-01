#include "Ghost.h"
#include "Map.h"
#include <iostream>

Ghost::Ghost(int x, int y) : x(x), y(y), prevX(x), prevY(y), startX(x), startY(y), state(std::make_shared<WanderState>()) {}

void Ghost::move(int pacX, int pacY) {
    prevX = x; // Simpan posisi sebelumnya
    prevY = y;

    int newX = x, newY = y;
    state->move(this, newX, newY, pacX, pacY); // Panggil fungsi move dari state saat ini
    if (!Map::isWall(newX, newY)) {           // Periksa apakah posisi baru bukan tembok
        x = newX;
        y = newY;
    }

    // Debugging: Cetak posisi awal dan posisi saat ini
    std::cout << "Ghost current position: (" << x << ", " << y << "), base: (" << startX << ", " << startY << ")" << std::endl;
}

void Ghost::changeState(std::shared_ptr<GhostState> newState) {
    state = newState; // Ubah state Ghost
}

int Ghost::getPrevX() const { return prevX; }
int Ghost::getPrevY() const { return prevY; }
int Ghost::getX() const { return x; }
int Ghost::getY() const { return y; }
int Ghost::getStartX() const { return startX; }
int Ghost::getStartY() const { return startY; }
char Ghost::getSymbol() const { return 'G'; }
const char* Ghost::getStateName() const { return state->getName(); }