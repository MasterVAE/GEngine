#ifndef RENDER_H_
#define RENDER_H_

#include <stdio.h>

#include "object.h"

void Render(World_c* world);

typedef struct Rect
{
    double minX;
    double maxX;
    double minY;
    double maxY;
} Rect;

#endif