#include "Object.h"
#include "Cell.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    Ocean * ocean1 = new Ocean;
    ocean1->addObjects(Object_Type::prey,200);
    ocean1->addObjects(Object_Type::predator,200);
    ocean1->addObjects(Object_Type::stone,0);
    ocean1->write_results_to_file(ocean1->get_prey_amount(),ocean1->get_predator_amount(),
            ocean1->get_stone_amount(),0);
    std::cout << "\n\n" << std::endl;
    for (unsigned int i(0); i < 100; i++)
    {
        ocean1->run();
        cout << "\n\n" << std::endl;
        ocean1->print();
        if (i % 10)
            ocean1->write_results_to_file(ocean1->get_prey_amount(),ocean1->get_predator_amount(),
                                          ocean1->get_stone_amount(),i);
    }
/*
    "The amount of Preys : " << prey_amount << endl;
    stream<<"The amount of Predators : " << predator_amount << endl;
    stream  "The amount of Stones : " << stone_amount << endl;
*/

    return 0;

}