#include "Cell.h"

void Cell::init(Pair pair_coordinates, Ocean *oc)
{
    crd = pair_coordinates;
    ocean = oc;
}

void Cell::setObject(Object * obj)
{
    object = obj;
}

Object* Cell::getObject() const
{
    return object;
}

void Cell::killme()
{
    if(object)
    {
        delete object; // value pointed by this pointer is destroying, pointer to object is not destroying
        object = nullptr;  // set new value to pointer
    }
}

Ocean* Cell::getOcean ()
{
    return ocean;
}

Cell* Cell::find_prey()
{
    return ocean->find_prey(crd);
}

Cell* Cell::find_predator(){
    return ocean->find_predator(crd);
}

Cell* Cell::empty_cell_neighbor()
{
    return ocean->find_nullptr_cells(crd);
}