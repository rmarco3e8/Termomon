#include <iostream>
#include <fstream>
#include <string>
#include "termomon.h"
#include "map.h"
#include "player.h"
#include "game.h"
#include <filesystem>
namespace fs = std::filesystem;

/*
#define GRASS   '*'
#define EMPTY   ' '
#define PLAYER  'o'
#define WALL    '#'
*/

int main(int argc, char *argv[]) {

    std::string mapName;

    std::cout << "Enter a map from the following list:" << '\n' << '\n';

    fs::path path = fs::current_path() += "/maps";
    
    for (const auto & entry: fs::directory_iterator(path)) {
        std::cout << entry.path().stem().string() << '\n';
    }

    std::cout << '\n';

    std::cin >> mapName;

    Game game = Game(mapName);

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    game.draw();

    int c;

    while(true) {
        c = getch();
        game.input(c);
        refresh();
    }

    endwin();

    return 0;
}