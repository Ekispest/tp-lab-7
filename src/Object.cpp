#include "Object.h"

Object_Type Object::get_type()
{
    return type_obj;
}


unsigned int Object::get_live()
{
    return life_time;
}

void Object::setlife_time(unsigned int life_t)
{
    life_time = life_t;
}

Object::Object(Cell * c):cell(c)
{
}

Cell* Object::getCell()
{
    return  cell;
}