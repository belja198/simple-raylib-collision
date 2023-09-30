#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

struct Player {
    float pos_x, pos_y;
    float width, height;
    float velocity_x, velocity_y;
    float acceleration_x;
    float jump_force;
    bool can_jump;
    Color color;
};


void updatePlayer(Player* player);


#endif