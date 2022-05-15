#include "player.h"



Player::Player(Map &map_in) {
    current_map = &map_in;
    terobux = 0;
}

void Player::input(int c) {
    if (isMovementKey(c)) {
        current_map->move(c);
    }
}

bool Player::isMovementKey(int c) {

    if (c == KEY_UP || c == KEY_DOWN || c == KEY_LEFT || c == KEY_RIGHT) {
        return true;
    }
    return false;
}