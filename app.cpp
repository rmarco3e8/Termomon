#include <iostream>
#include <fstream>
#include <string>
#include "termomon.h"
#include <ncurses.h>

/*
#define GRASS   '*'
#define EMPTY   ' '
#define PLAYER  'o'
#define WALL    '#'
*/

int main(int argc, char *argv[]) {

    std::string mapName = argv[0];
    std::cout << mapName << 'n';

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    move(2,3);

    int c = getch();

    if (c == KEY_UP) {
        printw("up");
    }

    refresh();

    getch();

    endwin();

    return 0;
}