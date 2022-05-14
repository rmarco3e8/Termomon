#include <iostream>
#include <string>
#include "termomon.h"


int main(int argc, char *argv[]) {

    TypeHelper t_helper;

    Type test1 = Type::drip;
    Type test2 = Type::heat;

    std::string result = t_helper.printTypeBattle(test1, test2);

    std::cout << result << '\n';

    return 0;
}