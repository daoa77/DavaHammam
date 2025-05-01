#ifndef MAP_H
#define MAP_H

#include <vector>
#include <utility> // Untuk std::pair

const int HEIGHT = 12;
const int WIDTH = 12;

class Map {
public:
    static char map[HEIGHT][WIDTH];
    static bool isWall(int x, int y);
    static bool isPowerPellet(int x, int y);
    static void eatPowerPellet(int x, int y);

    // Fungsi untuk menemukan jalur terpendek
    static std::vector<std::pair<int, int>> findPath(int startX, int startY, int targetX, int targetY);
};

#endif