
#ifndef GHOSTDECORATOR_H
#define GHOSTDECORATOR_H

#include "Ghost.h"

class GhostDecorator : public Ghost {
protected:
    std::shared_ptr<Ghost> base;
public:
    GhostDecorator(std::shared_ptr<Ghost> ghost);
    void move(int pacX, int pacY) override;
    char getSymbol() const override;
    const char* getStateName() const override;
};

class SpeedBoostDecorator : public GhostDecorator {
public:
    SpeedBoostDecorator(std::shared_ptr<Ghost> ghost);
    void move(int pacX, int pacY) override;
    char getSymbol() const override;
};

#endif
