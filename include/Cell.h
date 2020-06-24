#pragma once
#include "Object.h"
#include "Ocean.h"
#include "common_settings.h"
class Ocean;
class Cell{
    friend Ocean;
private:
    Pair crd;
    Object* object;
    Ocean* ocean;
public:
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr):
    crd(p), object(nullptr), ocean(oc){}
    void setObject(Object* obj);
    void killme();
    Object* getObject() const;
    void init(Pair p, Ocean* oc);
    Ocean * getOcean();
    Cell* empty_cell_neighbor();
    Cell* find_prey();
    Cell* find_predator();

};