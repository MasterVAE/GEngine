#include "behaviours.h"
#include "object.h"

int bhvr1(Game_t*, Object_t* my_object)
{
    my_object->transform.x += 0.1;
    my_object->transform.y += 0.1;
    return 1;
}