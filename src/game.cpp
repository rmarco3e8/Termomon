#include "../inc/game.h"

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
    else if (c == int('2')) {
        queuedAction = 2;
        return true;
    }
    return false;
}

void Game::useAction(int d) {
    if (queuedAction == 1) {
        earth_3(d);
    }
    else if (queuedAction == 2) {
        earth_1(d);
    }
    queuedAction = 0;
}

void Game::input(int c) {
    if (awaitingDirection) {
        if (isMovementKey(c)) {
            useAction(c);
        }
        else {
            printMessage("Cancelled.");
        }
        awaitingDirection = false;
        queuedAction = 0;
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
        message += " Raise mountain: 1";
        message += " Flatten mountain: 2";
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

void Game::earth_1(int d) {

    int x = current_map.getPlayerX();
    int y = current_map.getPlayerY();

    std::string message = "Flattened mountains ";

    switch(d) {
    
    case KEY_UP:

        message += "towards the North.";

        if (current_map.getCharAt(x, y-1) == '^') {
            current_map.place(x, y-1, '.');
        }
    break;

    case KEY_DOWN:

        message += "towards the South.";

        if (current_map.getCharAt(x, y+1) == '^') {
            current_map.place(x, y+1, '.');
        }
    break;

    case KEY_LEFT:

        message += "towards the West.";

        if (current_map.getCharAt(x-1, y) == '^') {
            current_map.place(x-1, y, '.');
        }
    break;

    case KEY_RIGHT:

        message += "towards the East.";

        if (current_map.getCharAt(x+1, y) == '^') {
            current_map.place(x+1, y, '.');
        }
    break;
    }
    draw();
    refresh();
    printMessage(message);
}

void Game::earth_3(int d) {

    int x = current_map.getPlayerX();
    int y = current_map.getPlayerY();

    std::string message = "Raised mountains ";

    switch(d) {
    
    case KEY_UP:

        message += "towards the North.";

        while (!current_map.blockedUp(x, y)) {
            y--;
            current_map.placeMountain(x, y);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            draw();
            refresh();
        }
    break;

    case KEY_DOWN:

        message += "towards the South.";

        while (!current_map.blockedDown(x, y)) {
            y++;
            current_map.placeMountain(x, y);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            draw();
            refresh();
        }
    break;

    case KEY_LEFT:

        message += "towards the West.";

        while (!current_map.blockedLeft(x, y)) {
            x--;
            current_map.placeMountain(x, y);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            draw();
            refresh();
        }
    break;

    case KEY_RIGHT:

        message += "towards the East.";

        while (!current_map.blockedRight(x, y)) {
            x++;
            current_map.placeMountain(x, y);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            draw();
            refresh();
        }
    break;
    }

    printMessage(message);
}