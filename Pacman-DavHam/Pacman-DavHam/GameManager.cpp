#include "GameManager.h"
#include "Map.h"
#include "GhostFactory.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

// Inisialisasi vektor Ghost statik
std::vector<std::shared_ptr<Ghost>> GameManager::ghosts;

GameManager::GameManager() : pac(10, 1) {
    srand(time(0));
    ghosts.push_back(GhostFactory::createGhost("Clyde", 5, 5));
}

// Fungsi untuk merender peta, Pacman, dan Ghost
void render(const Pacman& pacman, const std::vector<std::shared_ptr<Ghost>>& ghosts) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            bool printed = false;
            if (i == pacman.getX() && j == pacman.getY()) {
                cout << pacman.getSymbol() << " ";
                printed = true;
            } else {
                for (const auto& g : ghosts) {
                    if (g->getX() == i && g->getY() == j) {
                        cout << g->getSymbol() << " ";
                        printed = true;
                        break;
                    }
                }
            }
            if (!printed) cout << Map::map[i][j] << " ";
        }
        cout << endl;
    }

    for (const auto& g : ghosts) {
        cout << "Ghost at (" << g->getX() << ", " << g->getY() << ") is in state: " << g->getStateName() << endl;
    }
}

// Loop utama permainan
void GameManager::run() {
    char input;
    while (true) {
        system("cls");
        render(pac, ghosts);

        // Cek kondisi menang (power pellet habis)
        if (checkWinCondition()) {
            cout << "\n YOU WIN! Semua power pellet telah dimakan! \n";
            break;
        }

        if (_kbhit()) {
            input = _getch();
            if (input == 'q') break;
            pac.setDirection(input);
        }

        pac.move(*this);
        for (auto& ghost : ghosts) {
            ghost->move(pac.getX(), pac.getY());
        }

        Sleep(400);
    }
}

// Trigger state frightened untuk semua ghost
void GameManager::triggerFrightenedState() {
    for (auto& ghost : ghosts) {
        ghost->changeState(std::make_shared<FrightenedState>());
    }
}

// Fungsi untuk cek apakah semua power pellet sudah dimakan
bool GameManager::checkWinCondition() {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (Map::map[i][j] == 'O') {
                return false; // Masih ada power pellet
            }
        }
    }
    return true; // Semua power pellet sudah habis
}
