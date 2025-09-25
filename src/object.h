#ifndef OBJECT_H_
#define OBJECT_H_

#include <stdio.h>

#include "main.h"

typedef struct Transform_c{
    double x;
    double y;

    double rotation;
} Transform;

typedef struct Render_c {
    double size_x;
    double size_y;
} Render_c;

typedef struct Object_c{
    Transform_c tranform;
    Render_c render;
    void (*behaviour1)(Object_c* myself);
} Object_c;


Object_c* Create_Object();

#endif