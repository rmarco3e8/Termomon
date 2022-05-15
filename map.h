#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <tuple>


class Map {
public:

    Map(std::string mapName);

    void readMapFile();

    void move(char c);

private:

    std::string mapName;
    int height;
    int width;
    std::tuple<int,int> playerLocation;
    std::vector<std::vector<char>> map;
    char underPlayer;
};

#endif