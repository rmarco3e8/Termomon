#include <iostream>
#include <fstream>
#include <string>
#include "termomon.h"
#include "map.h"
#include "player.h"

/*
#define GRASS   '*'
#define EMPTY   ' '
#define PLAYER  'o'
#define WALL    '#'
*/

int main(int argc, char *argv[]) {

    std::string mapName = argv[1];
    Map map = Map(mapName);
    Player player = Player(map);

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    map.draw();

    int c;

    while(true) {
        c = getch();
        player.input(c);
        //refresh();
    }

    endwin();

    return 0;
}