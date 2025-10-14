#include <stdlib.h>
#include <string.h>

#include "object.h"

Object_t* Create_Object()
{
    Object_t* obj = (Object_t*)calloc(1, sizeof(Object_t));
    return obj;
}