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

int TypeHelper::type_vs(Type type1, Type type2) {

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
    
    else if (type1 == heat && type2 == drip) {
        return true;
    }

    else if (type1 == drip && type2 == plant) {
        return true;
    }

    else if (type1 == plant && type2 == heat) {
        return true;
    }

    return false;
}

bool TypeHelper::checkVeryEffective(Type &type1, Type &type2) {

    if (type1 == type2) {
        return true;
    }
    
    else if (type1 == drip && type2 == heat) {
        return true;
    }

    else if (type1 == plant && type2 == drip) {
        return true;
    }

    else if (type1 == heat && type2 == plant) {
        return true;
    }

    return false;
}