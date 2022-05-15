#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "player.h"
#include <string>


class Game {
public:

    Game(std::string mName);
    
    void input(int c);

    bool isMovementKey(int c);

    void draw();

    void printMessage(std::string message);


private:

    Map current_map;
    Player player;
};

#endif