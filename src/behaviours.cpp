#include "behaviours.h"
#include "object.h"

void bhvr1(World_c* world, Object_c* myself)
{
    myself->transform.x += 1;
}