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

    /*

    TypeHelper t_helper;

    Type test1 = Type::drip;
    Type test2 = Type::heat;

    std::string result = t_helper.printTypeBattle(test1, test2);

    std::cout << result << '\n';

    */

    std::fstream mapFile;
    mapFile.open("maps/sandbox.txt");
    
    std::string word;
    int width;
    int height;

    mapFile >> word;
    width = std::stoi(word);
    mapFile >> word;
    height = std::stoi(word);

    int x = 0;
    int y = 0;

    initscr();
    cbreak();
    noecho();

    while (mapFile >> word) {

        printw("%c", word[0]);
    }

    move(2,3);

    char c = getch();

    printw("%c", c);

    refresh();

    getch();

    endwin();

    return 0;
}