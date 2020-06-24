#include "Prey.h"
#include <iostream>

Prey::Prey(Cell * cell):Object(cell)
{
    life_time = Life_Time_Prey;
    type_obj = Object_Type::prey;

}


void Prey::move()
{
    Cell* new_cell = cell->empty_cell_neighbor();
    if (new_cell != nullptr)
    {
        cell->setObject(nullptr);
        cell = new_cell;
        new_cell->setObject(this);
    }
}

void Prey::reproduction()
{
    Cell* new_cell = cell->empty_cell_neighbor();
    Cell * predator_danger = cell->find_predator();
    if (new_cell != nullptr && predator_danger == nullptr)
    {
        auto* child = new Prey(new_cell);
        new_cell -> setObject(child);
        new_cell->getOcean()->add_stuff(child);
    }

}

char Prey::get_symbol()
{
    return Prey_symbol;
}


bool Prey::live()
{
    if (!life_time)
        return false;
    move();
    if (life_time < 0.3 * Life_Time_Prey)
    {
        reproduction();
    }
    life_time--;
    return true;

}