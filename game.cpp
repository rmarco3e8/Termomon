#include "game.h"

Game::Game(std::string mName):
    current_map(mName),
    player(),
    distribution(1, 8)
{
    inBattle = false;
    lvl_earth = 1;
    awaitingAction = false;
    awaitingDirection = false;
    int queuedAction = 0;
}

bool Game::isMovementKey(int c) {

    if (c == KEY_UP || c == KEY_DOWN || c == KEY_LEFT || c == KEY_RIGHT) {
        return true;
    }
    return false;
}

bool Game::isActionKey(int c) {
    if (c == int('1')) {
        queuedAction = 1;
        return true;
    }
}

void Game::useAction(int d) {
    if (queuedAction == 1) {
        earth(d);
    }

    queuedAction = 0;
}

void Game::input(int c) {
    if (awaitingDirection) {
        if (isMovementKey(c)) {
            useAction(c);
        }
        else {
            awaitingDirection = false;
            queuedAction = 0;
            printMessage("Cancelled.");
        }
        return;
    }
    if (awaitingAction) {
        if (isActionKey(c)) {
            awaitingDirection = true;
            awaitingAction = false;
            printMessage("Choose a direction.");
            return;
        }
    }
    if (inBattle) {

        //return;
    }
    else if (isMovementKey(c)) {
        current_map.move(c);

        if (encounterTile()) {
            if (rollBattle()) {
                startBattle();
            }
        }
    }
    else if (c == int('q')) {
        awaitingAction = true;
        std::string message = "Choose an action.";
        message += " Use earth: 1";
        printMessage(message);
    }
    else {
        printMessage(std::string(1, char(c)));
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

void Game::earth(int d) {

    std::string message = "";

    switch(c) {
    
    case KEY_UP:

        if (map[py-1][px] == '#') {
            message = "BONK!";
            break;
        }
        if (py != 0) {
            map[py][px] = underPlayer;
            py--;
            underPlayer = map[py][px];
            map[py][px] = 'o';
        }
    break;

    case KEY_DOWN:
        if (map[py+1][px] == '#') {
            message = "BONK!";
            break;
        }
        if (py != (h-1)) {
            map[py][px] = underPlayer;
            py++;
            underPlayer = map[py][px];
            map[py][px] = 'o';
        }
    break;

    case KEY_LEFT:
        if (map[py][px-1] == '#') {
            message = "BONK!";
            break;
        }
        if (px != 0 ) {
            map[py][px] = underPlayer;
            px--;
            underPlayer = map[py][px];
            map[py][px] = 'o';
        }
    break;

    case KEY_RIGHT:
        if (map[py][px+1] == '#') {
            message = "BONK!";
            break;
        }
        if (px != (w-1)) {
            map[py][px] = underPlayer;
            px++;
            underPlayer = map[py][px];
            map[py][px] = 'o';
        }
    break;
    }

    draw();
    printMessage(message);
}