#include "typeHelper.h"

/*
    TODO:
    on startup, populate a hashtable of every type matchup using these functions for faster lookup
*/



/*  
    ARGS:
    type1: attacking type
    type2: defending type

    Returns:
    -1 if not very effective
    0 if effective
    1 if very effective
*/

int TypeHelper::typeBattle(Type &type1, Type &type2) {

    if (checkNotEffective(type1, type2)) {
        return -1;
    }

    if (checkVeryEffective(type1, type2)) {
        return 1;
    }

    return 0;
}

bool TypeHelper::checkNotEffective(Type &type1, Type &type2) {

    if (type1 == type2) {
        return true;
    }
    
    else if (type1 == Type::heat && type2 == Type::drip) {
        return true;
    }

    else if (type1 == Type::drip && type2 == Type::plant) {
        return true;
    }

    else if (type1 == Type::plant && type2 == Type::heat) {
        return true;
    }

    return false;
}

bool TypeHelper::checkVeryEffective(Type &type1, Type &type2) {

    if (type1 == type2) {
        return true;
    }
    
    else if (type1 == Type::drip && type2 == Type::heat) {
        return true;
    }

    else if (type1 == Type::plant && type2 == Type::drip) {
        return true;
    }

    else if (type1 == Type::heat && type2 == Type::plant) {
        return true;
    }

    return false;
}

std::string TypeHelper::printType(Type type) {

    return typeLookup.at(type);
}

std::string TypeHelper::printResult(int res) {
    return battleLookup.at(res);
}

std::string TypeHelper::printTypeBattle(Type &type1, Type &type2) {

    std::string result = printResult(typeBattle(type1, type2));
    std::string t1_string = printType(type1);
    std::string t2_string = printType(type2);

    return t1_string + " is " + result + " against " + t2_string + ".";
}