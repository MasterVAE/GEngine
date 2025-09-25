#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "main.h"
#include "object.h"
#include "behaviours.h"

#define WIDTH 80
#define HEIGHT 24

void fast_write(const char* data, size_t length) {
    write(STDOUT_FILENO, data, length);
}

int main()
{
    World_c world;
    Startup(&world);

    while(1)
    {
        Update(&world);
        Render(&world);
        usleep(50000);
    }

    return 0;
}

void Startup(World_c* world)
{
    setvbuf(stdout, NULL, _IONBF, 0);

    world->screen = (char*)calloc(HEIGHT * (WIDTH + 1) + 1, sizeof(char));
    world->counter = 0;

    world->object_num = 1;
    world->object_list = (Object_c*)malloc(sizeof(Object_c));

    world->object_list[0] = *Create_Object();
    world->object_list[0].behaviour1 = bhvr1;
}

void Update(World_c* world)
{
    world->counter++;
    for(int i = 0; i < world->object_num; i++)
    {
        void (*beh)(World_c* world, Object_c* myself) = world->object_list[i].behaviour1;
        if(beh != NULL)
        {
            beh(world, world->object_list+i);
        }
    }
    if(world->counter > 200)
    {
        abort();
    }
}

void Render(World_c* world)
{
    char* screen = world->screen;
    int offset = 0;

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