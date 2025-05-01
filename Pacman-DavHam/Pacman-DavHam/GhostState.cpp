#include "GhostState.h"
#include "Ghost.h"
#include "Map.h"
#include <cstdlib>
#include <iostream>

void ChaseState::move(Ghost* ghost, int& x, int& y, int pacX, int pacY) {
    static int chaseCounter = 0; // Penghitung langkah untuk ChaseState
    chaseCounter++;

    // Gunakan pathfinding untuk mengejar Pacman
    auto path = Map::findPath(x, y, pacX, pacY);

    // Jika ada jalur, ambil langkah pertama
    if (!path.empty() && path.size() > 1) {
        x = path[1].first;
        y = path[1].second;
    }

    // Periksa tabrakan langsung atau silang dengan Pacman
    if ((x == pacX && y == pacY) || 
        (ghost->getPrevX() == pacX && ghost->getPrevY() == pacY && ghost->getX() == pacX && ghost->getY() == pacY)) {
        std::cout << "Game Over! Pacman collided with a Ghost in ChaseState." << std::endl;
        exit(0); // Keluar dari program
    }

    // Debugging: Cetak posisi Ghost
    std::cout << "Ghost chasing Pacman: (" << x << ", " << y << "), target: (" << pacX << ", " << pacY << ")" << std::endl;

    // Ubah ke WanderState setelah durasi tertentu (5 detik = 5 * 1000 ms / 400 ms per langkah = ~12 langkah)
    if (chaseCounter > 12) {
        std::cout << "ChaseState ended. Switching to WanderState." << std::endl;
        ghost->changeState(std::make_shared<WanderState>());
        chaseCounter = 0; // Reset penghitung
    }
}

const char* ChaseState::getName() { return "Chase"; }

void WanderState::move(Ghost* ghost, int& x, int& y, int pacX, int pacY) {
    int dir = rand() % 4;
    if (dir == 0 && x > 0) x--; // Move up
    else if (dir == 1 && x < HEIGHT - 1) x++; // Move down
    else if (dir == 2 && y > 0) y--; // Move left
    else if (dir == 3 && y < WIDTH - 1) y++; // Move right

    // Periksa tabrakan langsung atau silang dengan Pacman
    if ((x == pacX && y == pacY) || 
        (ghost->getPrevX() == pacX && ghost->getPrevY() == pacY && ghost->getX() == pacX && ghost->getY() == pacY)) {
        std::cout << "Game Over! Pacman collided with a Ghost in WanderState." << std::endl;
        exit(0); // Keluar dari program
    }

    // Secara acak ubah state ke ChaseState
    if (rand() % 100 < 30) { // 10% kemungkinan untuk masuk ke ChaseState
        std::cout << "Ghost switching to ChaseState randomly." << std::endl;
        ghost->changeState(std::make_shared<ChaseState>());
    }
}

const char* WanderState::getName() { return "Wander"; }

void FrightenedState::move(Ghost* ghost, int& x, int& y, int pacX, int pacY) {
    static int frightenedCounter = 0; // Penghitung langkah untuk FrightenedState
    frightenedCounter++;

    // Arah gerakan: atas, bawah, kiri, kanan
    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};

    int maxDistance = -1;
    int bestX = x, bestY = y;

    // Cari arah yang menjauh dari Pacman
    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        // Periksa apakah posisi valid dan bukan tembok
        if (newX >= 0 && newX < HEIGHT && newY >= 0 && newY < WIDTH && !Map::isWall(newX, newY)) {
            int distance = (newX - pacX) * (newX - pacX) + (newY - pacY) * (newY - pacY); // Hitung jarak kuadrat
            if (distance > maxDistance) {
                maxDistance = distance;
                bestX = newX;
                bestY = newY;
            }
        }
    }

    // Perbarui posisi Ghost ke arah yang menjauh
    x = bestX;
    y = bestY;

    // Debugging: Cetak posisi Ghost
    std::cout << "Ghost fleeing from Pacman: (" << x << ", " << y << "), Pacman at: (" << pacX << ", " << pacY << ")" << std::endl;

    // Jika bertemu Pacman (tabrakan langsung atau silang)
    if ((x == pacX && y == pacY) || 
        (ghost->getPrevX() == pacX && ghost->getPrevY() == pacY && ghost->getX() == pacX && ghost->getY() == pacY)) {
        ghost->changeState(std::make_shared<ReturnToBaseState>());
    }

    // Ubah ke WanderState setelah durasi tertentu (7 detik = 7 * 1000 ms / 400 ms per langkah = ~17 langkah)
    if (frightenedCounter > 17) {
        std::cout << "FrightenedState ended. Switching to WanderState." << std::endl;
        ghost->changeState(std::make_shared<WanderState>());
        frightenedCounter = 0; // Reset penghitung
    }
}

const char* FrightenedState::getName() { return "Frightened"; }

void ReturnToBaseState::move(Ghost* ghost, int& x, int& y, int, int) {
    int baseX = ghost->getStartX(); // Posisi awal X
    int baseY = ghost->getStartY(); // Posisi awal Y

    // Temukan jalur terpendek ke base
    auto path = Map::findPath(x, y, baseX, baseY);

    // Jika ada jalur, ambil langkah pertama
    if (!path.empty() && path.size() > 1) {
        x = path[1].first;
        y = path[1].second;
    }

    // Debugging: Cetak posisi Ghost
    std::cout << "Ghost moving to base: (" << x << ", " << y << "), target base: (" << baseX << ", " << baseY << ")" << std::endl;

    // Jika sudah sampai di rumah, ubah state kembali ke WanderState
    if (x == baseX && y == baseY) {
        std::cout << "Ghost reached base. Switching to WanderState." << std::endl;
        ghost->changeState(std::make_shared<WanderState>());
    }
}

const char* ReturnToBaseState::getName() { return "ReturnToBase"; }