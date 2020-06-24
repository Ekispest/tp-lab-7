#include "Stone.h"
#include <Cell.h>
#include <Object.h>

Stone::Stone(Cell *cell)
{
    life_time = Life_Time_Stone;
    type_obj = Object_Type::stone;
}

char Stone::get_symbol()
{
    return Stone_symbol;
}

bool Stone::live()
{
    if (life_time == 0)
        return false;

    life_time--;
    return true;

}

void Stone::move()
{

}

void Stone::reproduction()
{

}