#include "ghost.h"
#include "pacman.h"
#include "map.h"

int main() {
    Map gameMap;
    gameMap.draw();

    Pacman pacman;
    pacman.move();

    RedGhost redGhost;
    BlueGhost blueGhost;

    redGhost.move();
    blueGhost.move();

    return 0;
}