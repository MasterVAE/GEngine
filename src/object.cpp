#include <stdlib.h>
#include <string.h>

#include "object.h"

Object_c* Create_Object()
{
    Object_c* object = (Object_c*)malloc(sizeof(Object_c));
    object->transform = {0, 0, 0};
    object->render = {10, 10, '@'};
    object->behaviour1 = NULL;

    return object;
}