#ifndef RENDER_H_
#define RENDER_H_

#include <stdio.h>

#include "object.h"

void Render(World_c* world);

typedef struct Rect
{
    int minX;
    int maxX;
    int minY;
    int maxY;
} Rect;

#endif