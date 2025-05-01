#ifndef PACMAN_H
#define PACMAN_H

class GameManager; // Forward declaration

class Pacman {
private:
    int x, y;
    int prevX, prevY; // Posisi sebelumnya
    char lastDirection;
public:
    Pacman(int x, int y);
    void move(GameManager& gameController); // Pass GameManager reference
    void setDirection(char direction);
    int getX() const;
    int getY() const;
    int getPrevX() const; // Getter untuk posisi sebelumnya X
    int getPrevY() const; // Getter untuk posisi sebelumnya Y
    char getSymbol() const;
};

#endif