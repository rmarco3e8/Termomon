#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <string>
#include <vector>
#include <ncurses.h>


class Map {
public:

    Map(std::string mapName);

    void readMapFile();

    void move(int c);

    void draw();

    bool isMovementKey(int c);


private:

    std::string mapName;
    int h;
    int w;
    int py, px; // (row, col), (y, x)
    std::vector<std::vector<char>> map;
    char underPlayer;
};

#endif