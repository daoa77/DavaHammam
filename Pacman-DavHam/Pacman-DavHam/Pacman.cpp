#include "Pacman.h"
#include "Map.h"
#include "GameManager.h"

Pacman::Pacman(int x, int y) : x(x), y(y), prevX(x), prevY(y), lastDirection(' ') {}

void Pacman::move(GameManager& gameController) {
    prevX = x; // Simpan posisi sebelumnya
    prevY = y;

    int newX = x, newY = y;
    switch (lastDirection) {
        case 'w': newX--; break;
        case 's': newX++; break;
        case 'a': newY--; break;
        case 'd': newY++; break;
    }
    if (!Map::isWall(newX, newY)) {
        x = newX;
        y = newY;

        if (Map::isPowerPellet(x, y)) {
            Map::eatPowerPellet(x, y);
            gameController.triggerFrightenedState();
        }
    }
}

void Pacman::setDirection(char direction) {
    lastDirection = direction; // Simpan arah terakhir
}

int Pacman::getPrevX() const { return prevX; }
int Pacman::getPrevY() const { return prevY; }
int Pacman::getX() const { return x; }
int Pacman::getY() const { return y; }
char Pacman::getSymbol() const { return 'P'; }