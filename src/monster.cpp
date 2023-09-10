#include "../inc/monster.h"

Monster::Monster() {

}

int Monster::getMonsterX() {
  return this->mx;
}

int Monster::getMonsterY() {
  return this->my;
}

void Monster::setHealth(int newHealth) {
  this->health = newHealth;
}

// void Monster::die() {
//   Game::printMessage(this->cry());
// }

int Monster::calculateDamageTaken(int damage) {
  return std::max(0, damage - this->defense);
}

void Monster::takeDamage(int damage) {
  int calculatedDamage = calculateDamageTaken(damage);
  setHealth(std::max(0, this->health - calculatedDamage));
}

void Monster::setAttackPattern(std::vector<std::vector<char>> newAttackPattern) {
  this->attackPattern = newAttackPattern;
};