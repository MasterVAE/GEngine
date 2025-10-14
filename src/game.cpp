#include "game.h"

void GameManager_run(Game* game)
{
    for(size_t i = 0; i < game->object_num; i++)
    {
        Object_t* obj = &game->object_list[i];
        for(size_t j = 0; j < obj->behaviour_count; j++)
        {
            obj->behaviour_list[j](game, obj);
        }
    }
}
