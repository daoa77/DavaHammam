#include "GhostFactory.h"
#include "GhostTypes.h" // Tambahkan header untuk tipe Ghost
#include <stdexcept>

std::shared_ptr<Ghost> GhostFactory::createGhost(const std::string& type, int x, int y) {
  if (type == "Blinky") {
        return std::make_shared<Blinky>(x, y);
    } else if (type == "Pinky") {
        return std::make_shared<Pinky>(x, y);
    } else if (type == "Inky") {
        return std::make_shared<Inky>(x, y);
    } else if (type == "Clyde") {
        return std::make_shared<Clyde>(x, y);
    } else {
        throw std::invalid_argument("Unknown ghost type: " + type);
    }       
    
    return nullptr; // untuk memastikan semua jalur return sesuatu
    }