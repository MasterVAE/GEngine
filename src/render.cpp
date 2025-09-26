#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#include "object.h"
#include "render.h"

#define WIDTH 80
#define HEIGHT 24

void fast_write(const char* data, size_t length) {
    write(STDOUT_FILENO, data, length);
}

void SetPixel(World_c* world, size_t x, size_t y, char pixel)
{
    world->screen[7 + y * (WIDTH+1) + x] = pixel;
}

void Render(World_c* world)
{
    char* screen = world->screen;
    memset(screen, ' ', HEIGHT * (WIDTH + 1) + 8);
    memcpy(screen, "\033[2J\033[H", 7);

    for(size_t i = 0; i < world->object_num; i++)
    {
        Transform_c* trn = &world->object_list[i].transform; 
        Render_c* rnd = &world->object_list[i].render; 
        if(rnd != NULL)
        {
            Rect rect = {(int)rint(trn->x - rnd->size_x/2), (int)rint(trn->x + rnd->size_x/2), (int)rint(trn->y - rnd->size_y/2), (int)rint(trn->y + rnd->size_y/2)};
            for(int y = rect.minY; y <= rect.maxY; y++)
            {
                if(y >= 0 && y < HEIGHT)
                {
                    for(int x = rect.minX; x <= rect.maxX; x++)
                    {
                        if(x >= 0 && x < WIDTH)
                        {
                            SetPixel(world, x, y, 'A' + x);
                        }
                    }
                }
            }
        }
    }

        
    for(int y = 0; y < HEIGHT; y++) {
        SetPixel(world, WIDTH, y, '\n');
    }
    //SetPixel(world, WIDTH+1, HEIGHT-1, '\0');
        
    fast_write(screen, HEIGHT * (WIDTH + 1) + 8);
}