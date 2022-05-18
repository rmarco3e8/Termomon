#include "map.h"


Map::Map(std::string mName) {
    mapName = mName;
    
    for (int i = 0; i < textboxLength; i++) {
        textbox.push_front(std::string(40, ' '));
    }

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
                py = row;
                px = col;
                map[row][col] = 'o';
                underPlayer = '.';
            }
        }
    }

}

bool Map::blockedUp(int x, int y) {
    if (y == 0) {
        return true;
    }
    if (map[y-1][x] == '#' || map[y-1][x] == '^') {
        return true;
    }
    return false;
}

bool Map::blockedDown(int x, int y) {
    if (y == h-1) {
        return true;
    }
    if (map[y+1][x] == '#' || map[y+1][x] == '^') {
        return true;
    }
    return false;
}

bool Map::blockedLeft(int x , int y) {
    if (x == 0) {
        return true;
    }
    if (map[y][x-1] == '#' || map[y][x-1] == '^') {
        return true;
    }
    return false;
}

bool Map::blockedRight(int x, int y) {
    if (x == w-1) {
        return true;
    }
    if (map[y][x+1] == '#' || map[y][x+1] == '^') {
        return true;
    }
    return false;
}

void Map::placeMountain(int x, int y) {
    map[y][x] = '^';
}

void Map::move(int c) {

    std::string message = "";

    switch(c) {
    
    case KEY_UP:

        if (map[py-1][px] == '#' || map[py-1][px] == '^') {
            message = "BONK!";
            break;
        }
        if (py != 0) {
            map[py][px] = underPlayer;
            py--;
            underPlayer = map[py][px];
            map[py][px] = 'o';
        }
    break;

    case KEY_DOWN:
        if (map[py+1][px] == '#' || map[py+1][px] == '^') {
            message = "BONK!";
            break;
        }
        if (py != (h-1)) {
            map[py][px] = underPlayer;
            py++;
            underPlayer = map[py][px];
            map[py][px] = 'o';
        }
    break;

    case KEY_LEFT:
        if (map[py][px-1] == '#' || map[py][px-1] == '^') {
            message = "BONK!";
            break;
        }
        if (px != 0 ) {
            map[py][px] = underPlayer;
            px--;
            underPlayer = map[py][px];
            map[py][px] = 'o';
        }
    break;

    case KEY_RIGHT:
        if (map[py][px+1] == '#' || map[py][px+1] == '^') {
            message = "BONK!";
            break;
        }
        if (px != (w-1)) {
            map[py][px] = underPlayer;
            px++;
            underPlayer = map[py][px];
            map[py][px] = 'o';
        }
    break;
    }

    draw();
    printMessage(message);
}

void Map::draw() {

    for (int row = 0; row < h; ++row) {
        for (int col = 0; col < w; ++col) {
            mvaddch(row, col*2, map[row][col]);
        }
    }
}

void Map::printMessage(std::string message) {

    if (message == "") {
        return;
    }

    message.resize(40, ' ');

    textbox.push_front(message);
    textbox.pop_back();

    for (int i = textbox.size(); i > 0; i--) {
        mvprintw(h + i + 1, 0, textbox.front().c_str());
        std::string temp = textbox.front();
        textbox.pop_front();
        textbox.push_back(temp);
    }
}

void Map::clearMap() {
    for (int row = 0; row < h; ++row) {
        for (int col = 0; col < w; ++col) {
            mvaddch(row, col*2, ' ');
        }
    }
}

bool Map::encounterTile() {
    if (underPlayer == '*') {
        return true;
    }
    return false;
}

int Map::getPlayerX() {
    return px;
}

int Map::getPlayerY() {
    return py;
}