#ifndef MOVE_H
#define MOVE_H

#include <vector>
#include <string>
#include "typeHelper.h"


class Move {


public:

    // Constructor
    Move();

    // Destructor
    ~Move();


private:

    Type type;
    int damage;
    //damageType


};

#endif