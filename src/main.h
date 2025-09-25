#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>

#include "object.h"

typedef struct World_c{
    size_t object_num;
    Object_c* object_list;

    char* screen;

    size_t counter;

} World_c;


void Update(World_c* world);
void Render(World_c* world);
void Startup(World_c* world);

#endif