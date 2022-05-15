#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "player.h"
#include <string>
#include <random>


class Game {
public:

    Game(std::string mName);
    
    void input(int c);

    bool isMovementKey(int c);

    void draw();

    void printMessage(std::string message);

    void clearMap();

    void startBattle();

    //void loadBattle();

    bool encounterTile();

    bool rollBattle();

private:

    Map current_map;
    Player player;
    bool inBattle;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;
};

#endif