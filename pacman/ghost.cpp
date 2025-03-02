#include "ghost.h"

Ghost::~Ghost() {}

void RedGhost::move() {
    cout << "Red Ghost is moving aggressively!" << endl;
}

void BlueGhost::move() {
    cout << "Blue Ghost is moving strategically!" << endl;
}
