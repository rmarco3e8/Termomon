#ifndef MONSTER_H
#define MONSTER_H

#include <vector>
#include <string>
#include <algorithm>

class Monster {
public:

  // virtual ~Monster();

  virtual std::string cry();

  int getMonsterX();

  int getMonsterY();

  void setHealth(int newHealth);

  // void die();

  void takeDamage(int damage);

  void setAttackPattern(std::vector<std::vector<char>> newAttackPattern);

protected:
  Monster();

private:
  int calculateDamageTaken(int damage);

  int health;
  int defense;
  int attack;
  int moveSpeed;
  std::vector<std::vector<char>> attackPattern;

  int mx;
  int my;
};

#endif