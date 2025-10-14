#ifndef OBJECT_H_
#define OBJECT_H_

#include <stdio.h>

typedef struct Data             Data_t;
typedef struct Game             Game_t;

typedef struct InputManager     InputManager_t;
typedef struct GameManager      GameManager_t;
typedef struct RenderManager    RenderManager_t;

typedef struct Transform        Transform_t;
typedef struct Render           Render_t;
typedef struct Object           Object_t;

union data_union                //ОБЪЕДИНЕНИЕ ДЛЯ ХРАНЕНИЯ ПРОИЗВОЛЬНЫХ ДАННЫХ
{
    char c;
    int i;
    float f;
    double d;
    char* s;
};

typedef struct Data             //СЛОВАРЬ
{
    const char* label;
    data_union value;
} Data_t;

typedef struct Transform        //ХРАНИТ ДАННЫЕ ОБ ГЕОМЕТРИИ ОБЪЕКТА
{
    double x;
    double y;

    double rotation;
} Transform_t;

typedef struct Render           //ХРАНИТ ДАННЫЕ ОБ РЕНДЕРЕ ОБЪЕКТА
{
    double size_x;
    double size_y;

    char texture;
} Render_t;

typedef struct Object           //ХРАНИТ ДАННЫЕ ОБ ОБЪЕКТЕ
{
    Object_t* parent;

    Transform_t transform;
    Render_t render;

    size_t data_count;
    Data_t* data;

    size_t behaviour_count;
    int (**behaviour_list)(Game_t*, Object_t*);
} Object_t;

typedef struct InputManager     //ХРАНИТ ДАННЫЕ ДИСПЕТЧЕРА ВВОДА
{

} InputManager_t;

typedef struct GameManager      //ХРАНИТ ДАННЫЕ ДИСПЕТЧЕРА ВЫВОДА
{
    
} GameManager_t;

typedef struct RenderManager    //ХРАНИТ ДАННЫЕ ДИСПЕТЧЕРА РЕНДЕРА
{
    char* screen;
} RenderManager_t;

typedef struct Game             //ХРАНИТ ВСЕ ДАННЫЕ
{   
    InputManager_t  input;
    GameManager_t   game;
    RenderManager_t render;

    size_t object_num;
    Object_t* object_list;
} Game_t;


Object_t* Create_Object();

#endif