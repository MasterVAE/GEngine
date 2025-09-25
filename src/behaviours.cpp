#include "behaviours.h"
#include "object.h"
#include "main.h"

void bhvr1(World_c* world, Object_c* myself)
{
    printf("%lu\n", world->counter);
    printf("%g\n", myself->transform.x);
}