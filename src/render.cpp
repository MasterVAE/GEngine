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


void Render(World_c* world)
{
    char* screen = world->screen;
    int offset = 0;
    memset(screen, 0, HEIGHT * (WIDTH + 1) + 1);

    for(size_t i = 0; i < world->object_num; i++)
    {
        Transform_c* trn = &world->object_list[i].transform; 
        Render_c* rnd = &world->object_list[i].render; 
        if(rnd != NULL)
        {
            Rect rect = {trn->x - rnd->size_x/2, trn->x + rnd->size_x/2, trn->y - rnd->size_y/2, trn->y + rnd->size_y/2};
        }
    }

    memcpy(screen, "\033[2J\033[H", 7);
    offset += 7;
        
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
                screen[offset++] = (x * y + y + world->counter) % 26 + 'A';
        }
        screen[offset++] = '\n';
    }
    screen[offset] = '\0';
        
    fast_write(screen, offset);
}