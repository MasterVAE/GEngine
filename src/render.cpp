#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#include "object.h"
#include "render.h"

void fast_write(const char*, size_t);
void SetPixel(Game_t*, size_t, size_t, char);

void fast_write(const char* data, size_t length)
{
    write(STDOUT_FILENO, data, length);
}

void SetPixel(char* screen, size_t x, size_t y, char pixel)
{
    screen[7 + y * (SCREEN_WIDTH+1) + x] = pixel;
}

void RenderManager_run(Game_t* game)
{
    char* screen = game->render.screen;
    memset(screen, ' ', SCREEN_HEIGHT * (SCREEN_WIDTH + 1) + 8);
    memcpy(screen, "\033[2J\033[H", 7);
    for(int y = 0; y < SCREEN_HEIGHT; y++) SetPixel(screen, SCREEN_WIDTH, y, '\n');
        
    // for(size_t i = 0; i < world->object_num; i++)
    // {
    //     Transform_c* trn = &world->object_list[i].transform; 
    //     Render_c* rnd = &world->object_list[i].render; 
    //     if(rnd != NULL)
    //     {
    //         Rect rect = {(int)rint(trn->x - rnd->size_x/2), (int)rint(trn->x + rnd->size_x/2), (int)rint(trn->y - rnd->size_y/2), (int)rint(trn->y + rnd->size_y/2)};
    //         for(int y = rect.minY; y <= rect.maxY; y++)
    //         {
    //             if(y >= 0 && y < HEIGHT)
    //             {
    //                 for(int x = rect.minX; x <= rect.maxX; x++)
    //                 {
    //                     if(x >= 0 && x < WIDTH)
    //                     {
    //                         SetPixel(world, x, y, rnd->texture);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

        

    fast_write(screen, SCREEN_HEIGHT * (SCREEN_WIDTH + 1) + 8);
}