#include <iostream>
#include <fstream>
#include <string>
#include "../inc/termomon.h"
#include "../inc/map.h"
#include "../inc/player.h"
#include "../inc/game.h"
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

    fs::path path = fs::current_path().parent_path() += "/maps";
    
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