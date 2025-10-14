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

    game->render.screen = (char*)calloc(SCREEN_HEIGHT * (SCREEN_WIDTH + 1) + 8, sizeof(char));
    game->object_num = 1;
    game->object_list = (Object_t*)calloc(game->object_num, sizeof(Object_t));

    game->object_list[0] = *Create_Object();
    game->object_list[0].behaviour_count = 1;
    game->object_list[0].behaviour_list = (int (**)(Game_t*, Object_t*))calloc(game->object_list[0].behaviour_count, sizeof(int*));
    
    game->object_list[0].behaviour_list[0] = bhvr1;
    game->object_list[0].render.size_x = 10;
    game->object_list[0].render.size_y = 5;
    game->object_list[0].render.texture = '#';
}

int main()
{
    game = (Game_t*)calloc(1, sizeof(Game_t));
    Startup(game);

    for(size_t i = 0; i < 100; i++)
    {
        InputManager_run(game);
        GameManager_run(game);
        RenderManager_run(game);

        usleep(50000);
    }

    return 0;
}