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
void Termomon::takeDamage(int dmg);

void Termomon::die();

int Termomon::getHealth();

int Termomon::setHealth(int newHealth);






private:

int maxhealth;
int health;
bool alive;
Type type;


};

#endif