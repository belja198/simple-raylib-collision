#include"raylib.h"
#include "player.h"

void updatePlayer(Player* player) {
     //slidey movement
 /*   if (IsKeyDown(KEY_D)) {   //slidey movement
        player->velocity_x += player->acceleration_x * GetFrameTime();
        
    }
    else if (player->velocity_x > 0) {
        player->velocity_x -= player->acceleration_x * GetFrameTime();
    }
   

    if (IsKeyDown(KEY_A)) {
        player->velocity_x -= player->acceleration_x * GetFrameTime();
    }
    else if (player->velocity_x < 0) {
        player->velocity_x += player->acceleration_x * GetFrameTime();
    }

    player->pos_x += player->velocity_x * GetFrameTime();*/

    //regular movement
    if (IsKeyDown(KEY_W)) {
        player->velocity_y = - 200.0f;
    }

    if (IsKeyDown(KEY_S)) {
        player->velocity_y = + 200.0f;
    }

    player->pos_y += player->velocity_y * GetFrameTime();

    if (IsKeyDown(KEY_D)) {
        player->velocity_x = + 200.0f;
    }

    if (IsKeyDown(KEY_A)) {
        player->velocity_x = - 200.0f;
    }

    player->pos_x += player->velocity_x * GetFrameTime();

    //jumping and falling (for later maybe)


    //collision with collidables
  //  for (int i = 0; i < collidables_num; i++) {
   //     collisionResolustionRecs(player, &collidables[i]);
  //  }

// OLD CODE FOR COLLISION RESOLUTION, THE LOGIC IS CORRECT BUT IT NEEDS AN UPDATE
/*    if (CheckCollisionRecs(Rectangle{player->pos_x, player->pos_y, player->width, player->height}, Rectangle{f->pos_x, f->pos_y, f->width, f->height})) {
        
        if (player->pos_y < f->pos_y && player->velocity_y > 0)
            player->pos_y = f->pos_y - player->height;  //NORTH

        if (player->pos_y + player->height > f->pos_y + f->height && player->velocity_y < 0)
            player->pos_y = f->pos_y + f->height;   //SOUTH

        if (player->pos_x < f->pos_x && player->velocity_x > 0)
            player->pos_x = f->pos_x - player->width;   //WEST

        if (player->pos_x + player->width > f->pos_x + f->width && player->velocity_x < 0)
            player->pos_x = f->pos_x + f->width;    //EAST
    }   */

    player->velocity_y = 0;
    player->velocity_x = 0;    
}
