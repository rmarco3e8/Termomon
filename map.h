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

    int getPlayerX();

    int getPlayerY();

    bool blockedUp(int x, int y);
    
    bool blockedDown(int x, int y);

    bool blockedLeft(int x , int y);

    bool blockedRight(int x, int y);

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