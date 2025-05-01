
#include "GhostDecorator.h"

GhostDecorator::GhostDecorator(std::shared_ptr<Ghost> ghost) : Ghost(ghost->getX(), ghost->getY()), base(ghost) {}

void GhostDecorator::move(int pacX, int pacY) {
    base->move(pacX, pacY);
    x = base->getX();
    y = base->getY();
}

char GhostDecorator::getSymbol() const {
    return base->getSymbol();
}

const char* GhostDecorator::getStateName() const {
    return base->getStateName();
}

SpeedBoostDecorator::SpeedBoostDecorator(std::shared_ptr<Ghost> ghost) : GhostDecorator(ghost) {}

void SpeedBoostDecorator::move(int pacX, int pacY) {
    base->move(pacX, pacY);
    base->move(pacX, pacY); // double move for speed
    x = base->getX();
    y = base->getY();
}

char SpeedBoostDecorator::getSymbol() const {
    return 'S';
}
