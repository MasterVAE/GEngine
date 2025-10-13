#ifndef RENDER_H_
#define RENDER_H_

#include <stdio.h>

#include "object.h"

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 40;

void RenderManager_run(Game_t* game);

typedef struct Rect
{
    int minX;
    int maxX;
    int minY;
    int maxY;
} Rect;

#endif