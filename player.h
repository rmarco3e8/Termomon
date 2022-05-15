#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "map.h"
#include <ncurses.h>


class Player {
public:

    Player(Map &map_in);

    void input(int c);

    bool isMovementKey(int c);


private:

    //vector<Teromon> team;
    int terobux;
    Map * current_map;

};

#endif