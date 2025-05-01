#include "Map.h"
#include <queue>
#include <vector>
#include <utility>
#include <cstring> // Untuk memset

char Map::map[HEIGHT][WIDTH] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', 'O', '#'},
    {'#', ' ', '#', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', '#', '#', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

bool Map::isWall(int x, int y) {
    return map[x][y] == '#';
}

bool Map::isPowerPellet(int x, int y) {
    return map[x][y] == 'O';
}

void Map::eatPowerPellet(int x, int y) {
    if (map[x][y] == 'O') {
        map[x][y] = ' '; // Remove the Power Pellet
    }
}

// Fungsi untuk menemukan jalur terpendek menggunakan BFS
std::vector<std::pair<int, int>> Map::findPath(int startX, int startY, int targetX, int targetY) {
    // Arah gerakan: atas, bawah, kiri, kanan
    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};

    // Array untuk melacak apakah posisi sudah dikunjungi
    bool visited[HEIGHT][WIDTH];
    memset(visited, false, sizeof(visited));

    // Queue untuk BFS
    std::queue<std::pair<int, int>> q;
    std::queue<std::vector<std::pair<int, int>>> paths;

    // Inisialisasi BFS
    q.push({startX, startY});
    paths.push({{startX, startY}});
    visited[startX][startY] = true;

    // BFS Loop
    while (!q.empty()) {
        std::pair<int, int> current = q.front(); // Ambil elemen pertama dari queue
        int x = current.first;  // Ambil koordinat X
        int y = current.second; // Ambil koordinat Y
        auto path = paths.front();
        q.pop();
        paths.pop();

        // Jika mencapai target, kembalikan jalur
        if (x == targetX && y == targetY) {
            return path;
        }

        // Periksa semua arah
        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            // Periksa apakah posisi valid dan belum dikunjungi
            if (newX >= 0 && newX < HEIGHT && newY >= 0 && newY < WIDTH &&
                !visited[newX][newY] && !isWall(newX, newY)) {
                visited[newX][newY] = true;
                q.push({newX, newY});
                auto newPath = path;
                newPath.push_back({newX, newY});
                paths.push(newPath);
            }
        }
    }

    // Jika tidak ada jalur, kembalikan jalur kosong
    return {};
}