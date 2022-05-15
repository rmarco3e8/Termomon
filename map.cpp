#include "map.h"
#include <fstream>

Map::Map(std::string mapName) {

    this->mapName = mapName;

    readMapFile();
}

void Map::readMapFile() {

    std::fstream mapFile;
    mapFile.open("maps/" + mapName + ".txt");

    std::string height, width;
    mapFile >> height >> width;
    h = stoi(height);
    w = stoi(width);

    map = std::vector<std::vector<char>> (h, std::vector<char> (w, 'z'));

    std::string word;

    for (int row = 0; row < h; ++row) {
        for (int col = 0; col < w; ++col) {
            mapFile >> word;
            map[row][col] = word[0];

            if (word[0] == 'x') {
                py, px = row, col;
                map[row][col] = 'o';
                underPlayer = '.';
            }
        }
    }

}

void Map::move(char c) {

    switch(c) {
    
    case 'u':
        if (py != 0) {
            map[py][px] = underPlayer;
            py--;
            underPlayer = map[py][px];
            map[py][px] = 'o';
        }
    break;

    case 'd':
        if (py != (h-1)) {
            map[py][px] = underPlayer;
            py++;
            underPlayer = map[py][px];
            map[py][px] = 'o';
        }
    break;

    case 'l':
        if (px != 0) {
            map[py][px] = underPlayer;
            px--;
            underPlayer = map[py][px];
            map[py][px] = 'o';
        }
    break;

    case 'r':
        if (px != (w-1)) {
            map[py][px] = underPlayer;
            px++;
            underPlayer = map[py][px];
            map[py][px] = 'o';
        }
    break;
    }
}