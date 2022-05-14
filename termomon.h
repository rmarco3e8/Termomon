#ifndef TERMOMON_H
#define TERMOMON_H

#include "typeHelper.h"

#include <vector>
#include <string>


class Termomon {


public:

    // Constructor
    Termomon();

    // Destructor
    ~Termomon();

    /*
    Termomon takes damage
    */
    void takeDamage(int dmg);

    void die();

    int getHealth();

    int setHealth(int newHealth);


private:

    int maxhealth;
    int health;
    bool alive;
    Type type;


};

#endif