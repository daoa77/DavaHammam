
#ifndef GHOSTFACTORY_H
#define GHOSTFACTORY_H

#include "Ghost.h"
#include <memory>
#include <string>

class GhostFactory {
public:
    static std::shared_ptr<Ghost> createGhost(const std::string& type, int x, int y);
};

#endif
