#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "object.h"
#include "behaviours.h"
#include "render.h"

#define WIDTH 80
#define HEIGHT 24

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
    for(size_t i = 0; i < world->object_num; i++)
    {
        void (*beh)(World_c* world, Object_c* myself) = world->object_list[i].behaviour1;
        if(beh != NULL)
        {
            beh(world, world->object_list+i);
        }
    }
    if(world->counter > 200)
    {
        exit(0);
    }
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