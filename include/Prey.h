#pragma once
#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common_settings.h"

class Cell;
class Ocean;
class Object;

class Prey: public Object{
    friend  Cell;
    friend Ocean;
public:
    explicit Prey(Cell* cell);
    ~Prey(){};
    bool live () override;
    char get_symbol() override;
    void reproduction() override;
    void move() override;

};