#ifndef GHOSTSTATE_H
#define GHOSTSTATE_H

class Ghost;
class GhostState {
public:
    virtual void move(Ghost* ghost, int& x, int& y, int pacX, int pacY) = 0;
    virtual const char* getName() = 0;
    virtual ~GhostState() = default;
};

class ChaseState : public GhostState {
public:
    void move(Ghost* ghost, int& x, int& y, int pacX, int pacY) override;
    const char* getName() override;
};

class WanderState : public GhostState {
public:
    void move(Ghost* ghost, int& x, int& y, int pacX, int pacY) override;
    const char* getName() override;
};

class FrightenedState : public GhostState {
public:
    void move(Ghost* ghost, int& x, int& y, int pacX, int pacY) override; // Tambahkan pacX dan pacY
    const char* getName() override;
};

class ReturnToBaseState : public GhostState {
public:
    void move(Ghost* ghost, int& x, int& y, int, int) override;
    const char* getName() override;
};

#endif