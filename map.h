#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <string>
#include <vector>
#include <ncurses.h>
#include <deque>


class Map {
public:

    Map(std::string mapName);

    void readMapFile();

    void move(int c);

    void draw();

    bool isMovementKey(int c);

    void printMessage(std::string message);

    void clearMap();

    bool encounterTile();


private:

    std::string mapName;
    int h;
    int w;
    int py, px; // (row, col), (y, x)
    std::vector<std::vector<char>> map;
    char underPlayer;
    std::deque<std::string> textbox;
    int textboxLength = 6;
};

#endif