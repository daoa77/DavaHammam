#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Pacman.h"
#include "Ghost.h"
#include "GhostFactory.h"
#include "GhostDecorator.h"
#include <vector>
#include <memory>

class GameManager {
    private:
        Pacman pac;
        static std::vector<std::shared_ptr<Ghost>> ghosts; // Static declaration
    public:
        GameManager();
        void run();
        static void triggerFrightenedState(); // Static function

        bool checkWinCondition();

};

#endif