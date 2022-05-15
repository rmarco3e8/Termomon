#include <iostream>
#include <fstream>
#include <string>
#include "termomon.h"
#include <ncurses.h>
#include "map.h"

/*
#define GRASS   '*'
#define EMPTY   ' '
#define PLAYER  'o'
#define WALL    '#'
*/

int main(int argc, char *argv[]) {

    std::string mapName = argv[1];
    Map map = Map(mapName);

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    map.draw();

    int c;

    while(true) {
        c = getch();
        map.move(c);
        refresh();
    }

    endwin();

    return 0;
}