#pragma once
#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common_settings.h"

class Cell;
class Ocean;
class Object;

class Predator: public Object
        {
    friend  Cell;
    friend Ocean;
public:
    explicit Predator(Cell* cell);
    ~Predator() override = default ;
    bool live () override;
    char get_symbol() override;
    void reproduction() override;
    void move() override;
    bool to_have_a_breakfast();

private:
    int am_i_hungry = 20; // the satiety of the predator in percents
};