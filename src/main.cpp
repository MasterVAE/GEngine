#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "object.h"
#include "behaviours.h"

#include "input.h"
#include "game.h"

#include "render.h"

Game_t* game;

void Startup(Game* game)
{
    setvbuf(stdout, NULL, _IONBF, 0);

    game->render.screen = (char*)calloc(SCREEN_HEIGHT * (SCREEN_WIDTH + 1) + 1, sizeof(char));
    // world->counter = 0;

    // world->object_num = 2;
    // world->object_list = (Object_c*)calloc(world->object_num, sizeof(Object_c));

    // world->object_list[0] = *Create_Object();
    // world->object_list[0].behaviour1 = bhvr1;
    // world->object_list[0].render.texture = '#';

    // world->object_list[1] = *Create_Object();
    // world->object_list[1].behaviour1 = bhvr1;
    // world->object_list[1].render.texture = ' ';
    // world->object_list[1].transform.x = 0;
    // world->object_list[1].transform.y = 0;
    // world->object_list[1].render.size_x = 6;
    // world->object_list[1].render.size_y = 6;
}

int main()
{
    game = (Game_t*)calloc(1, sizeof(Game_t));
    Startup(game);

    while(1)
    {
        InputManager_run(game);
        GameManager_run(game);
        RenderManager_run(game);

        usleep(50000);
    }

    return 0;
}