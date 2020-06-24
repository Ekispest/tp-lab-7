#pragma once
#include <vector>
#include "Cell.h"
#include "Predator.h"
#include "Stone.h"
#include "Prey.h"
#include "common_settings.h"
#include "Object.h"
#include <list>
#include <fstream>

using namespace std;
class Ocean{
    friend Cell;
public:
    Ocean();
    ~Ocean();
    void print() const;
    void addObjects(Object_Type type, unsigned int objects_amount);
    void run();
    void deleteObjects(Object* obj);
    void add_stuff(Object* obj);
    Cell* find_nullptr_cells(Pair crd);
    Cell* find_prey(Pair crd);
    Cell* find_predator(Pair crd);
    unsigned int get_prey_amount();
    unsigned int get_stone_amount();
    unsigned int get_predator_amount();
    void write_results_to_file(unsigned int amount1,unsigned int amount2,unsigned int amount3, unsigned int iteration);

private:
    Cell** cells;
    list <Object*> stuff;





};