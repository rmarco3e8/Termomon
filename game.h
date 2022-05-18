#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "player.h"
#include <string>
#include <random>
#include <chrono>
#include <thread>

class Game {
public:

    Game(std::string mName);
    
    void input(int c);

    bool isMovementKey(int c);

    bool isActionKey(int c);

    void useAction(int d);

    void draw();

    void printMessage(std::string message);

    void clearMap();

    void startBattle();

    //void loadBattle();

    bool encounterTile();

    bool rollBattle();

    void earth(int d);

private:

    Map current_map;
    Player player;
    bool inBattle;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;
    int lvl_earth;
    bool awaitingAction;
    bool awaitingDirection;
    int queuedAction;
};

#endif