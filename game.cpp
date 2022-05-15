#include "game.h"

Game::Game(std::string mName):
    current_map(mName),
    player(),
    distribution(1, 8)
{
    inBattle = false;
}

bool Game::isMovementKey(int c) {

    if (c == KEY_UP || c == KEY_DOWN || c == KEY_LEFT || c == KEY_RIGHT) {
        return true;
    }
    return false;
}

void Game::input(int c) {
    if (inBattle) {

        return;
    }
    else if (isMovementKey(c)) {
        current_map.move(c);

        if (encounterTile()) {
            if (rollBattle()) {
                startBattle();
            }
        }
    }
}

void Game::draw() {
    current_map.draw();
}

void Game::printMessage(std::string message) {
    current_map.printMessage(message);
}

void Game::clearMap() {
    current_map.clearMap();
}

void Game::startBattle() {
    clearMap();
    printMessage("Encountered a wild Teromon!");
    //loadBattle();
    inBattle = true;
}

bool Game::encounterTile() {
    return current_map.encounterTile();
}

bool Game::rollBattle() {

    int dice_roll = distribution(generator);  // generates number in the range 1..8 
    if (dice_roll == 8) {
        return true;
    }
    return false;
}