#ifndef OBJECT_H_
#define OBJECT_H_

#include <stdio.h>

typedef struct Transform_c{
    double x;
    double y;

    double rotation;
} Transform;

typedef struct Render_c {
    double size_x;
    double size_y;

    char texture;
} Render_c;

typedef struct World_c World_c;
typedef struct Object_c Object_c;

typedef struct Object_c{
    Transform_c transform;
    Render_c render;
    void (*behaviour1)(World_c* world, Object_c* myself);
} Object_c;

typedef struct World_c{
    size_t object_num;
    Object_c* object_list;

    char* screen;

    size_t counter;

} World_c;


Object_c* Create_Object();

#endif