#pragma once

#include "common_settings.h"
#define  Stone_symbol '#'
#define  Prey_symbol 'f'
#define  Predator_symbol 'S'
enum Object_Type {prey, predator, stone};
class Ocean;
class Cell;
class Object{
protected:
    Cell *cell;
    unsigned int life_time;
    Object_Type type_obj;
public:
    Object(Cell * c = nullptr);
    virtual ~Object() = default;
    virtual bool live() = 0;
    virtual char get_symbol() = 0;
    virtual void reproduction() = 0;
    virtual void move() = 0;
    void setlife_time(unsigned int life_time);
    Cell* getCell();
    Object_Type get_type();
    unsigned int get_live();
};