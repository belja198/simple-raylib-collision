#include "raylib.h"
#include "player.h"

#define SCREEN_WIDTH    500
#define SCREEN_HEIGHT   500
//#define GRAVITY 300

#define NUM_OF_HORIZONTAL_TILES 10
#define NUM_OF_VERTICAL_TILES   10

#define TILE_WIDTH SCREEN_WIDTH / NUM_OF_HORIZONTAL_TILES
#define TILE_HEIGHT SCREEN_HEIGHT / NUM_OF_VERTICAL_TILES



typedef enum {WALL, FLOOR} TileType;

struct Tile {
    Color color;
    TileType type;
};

Tile tileMap[NUM_OF_HORIZONTAL_TILES][NUM_OF_VERTICAL_TILES];

/* FIX THIS LATER
void collisionResolustionRecs(Player* p, Tile* c) {
    Rectangle rectP = {p->pos_x, p->pos_y, p->width, p->height};
    Rectangle rectC = {c->pos_x, c->pos_y, c->width, c->height};

    if (CheckCollisionRecs(rectP, rectC)) {
        Rectangle collision_rect = GetCollisionRec(rectP, rectC);

        if (collision_rect.width >= collision_rect.height) {    //north or south
            if (p->pos_y < c->pos_y)
                p->pos_y = c->pos_y - p->height;  //north
            else
                p->pos_y = c->pos_y + c->height;   //south
        } else {    //west or east
            if (p->pos_x < c->pos_x)
                p->pos_x = c->pos_x - p->width;   //west
            else
               p->pos_x = c->pos_x + c->width;     //east 
        }
    }
}*/


int main() 
{
    // Initialization
    //--------------------------------------------------------------------------------------
    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib");

    tileMap[0][0] = {GRAY, WALL};
    tileMap[3][3] = {GRAY, WALL};
    tileMap[0][2] = {GRAY, WALL};

    Player player = {};
    player.pos_x = SCREEN_WIDTH/2;
    player.pos_y = 300;
    player.width = 20;
    player.height = 30;
    player.velocity_x = 0;
    player.velocity_y = 0;
    player.acceleration_x = 200.0f;
    player.jump_force = 200;
    player.can_jump = false;
    player.color = RED;



    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        updatePlayer(&player);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(SKYBLUE);
            DrawRectangle(player.pos_x, player.pos_y, player.width, player.height, player.color);
           
            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}