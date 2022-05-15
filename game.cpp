#include "game.h"

Game::Game(std::string mName):
    current_map(mName),
    player()
{
}

bool Game::isMovementKey(int c) {

    if (c == KEY_UP || c == KEY_DOWN || c == KEY_LEFT || c == KEY_RIGHT) {
        return true;
    }
    return false;
}

void Game::input(int c) {
    if (isMovementKey(c)) {
        current_map.move(c);
    }
}

void Game::draw() {
    current_map.draw();
}