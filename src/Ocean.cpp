#include "Ocean.h"
#include "Stone.h"
#include "Object.h"
#include "Prey.h"




using  namespace std;

Ocean::Ocean()
{
    cells  = new Cell*[N];
    for (size_t i(0);i < N;++i)
    {
        cells[i] = new Cell[M];
        for (size_t j(0);j < M;++j)
        {
            cells[i][j].init({i,j},this);
        }
    }

}


Ocean::~Ocean()
{
    for(size_t i(0); i < N; ++i)
        delete[]cells[i];
    delete[] cells;
    for(auto stuffs:stuff)
    {
        delete stuffs;
    }
}

void Ocean::print() const
{
    for (size_t i(0);i < N;++i)
    {
        for (size_t j(0);j < M;++j)
        {
           if(cells[i][j].getObject() != nullptr)
               cout << cells[i][j].getObject()->get_symbol();
           else
               cout << '.';
        }
        cout<< endl;
    }
}


void Ocean::add_stuff(Object *obj)
{
    stuff.push_back(obj);
}


void Ocean::addObjects(Object_Type type, unsigned int objects_amount)
{
    srand(time(NULL));
    for (unsigned int  i(0); i < objects_amount;)
    {
        unsigned  int x = rand() % M;
        unsigned  int y = rand() % N;
        if (cells[y][x].getObject())
            continue;
        Object* new_object = nullptr;
        switch (type)
        {
            case Object_Type::prey:
                new_object = new  Prey(&cells[y][x]);
                //new_object->getCell()->setObject(new_object);
                break;
            case Object_Type::predator:
                new_object = new Predator(&cells[y][x]);
                //new_object->getCell()->setObject(new_object);
                break;
            case Object_Type::stone:
                new_object = new Stone(&cells[y][x]);
                //new_object->getCell()->setObject(new_object);
                break;
            default:
                break;
        }
        cells[y][x].setObject(new_object);
        stuff.push_back(new_object);
        i++;

    }


}


void Ocean::deleteObjects(Object *obj)
{
        obj->getCell()->killme();
}


Cell* Ocean::find_nullptr_cells(Pair crd)
{
    for (int i(0);i < 8; ++i)
    {
        size_t new_x = crd.x + rand() % 3 - 1;
        size_t new_y = crd.y + rand() % 3 - 1;
        if (new_x < N && new_y < M)
            if (cells[new_x][new_y].getObject() == nullptr)
                return &cells[new_x][new_y];

    }
    return nullptr;
}


Cell* Ocean::find_prey(Pair crd)
{
    srand(time(NULL));
    for(int i(0); i < 8; ++i)
    {
        size_t new_x = crd.x + rand() % 3 - 1;
        size_t new_y = crd.y + rand() % 3 - 1;
        if (new_x < N && new_y < M)
            if (cells[new_x][new_y].getObject() && cells[new_x][new_y].getObject()->get_type() == Object_Type::prey)
                return &cells[new_x][new_y];

    }
    return nullptr;
}



Cell* Ocean::find_predator(Pair crd)
{
    srand(time(NULL));
    for(int i(0); i < 8; ++i)
    {
        size_t new_x = crd.x + rand() % 3 - 1;
        size_t new_y = crd.y + rand() % 3 - 1;
        if (new_x < N && new_y < M)
            if (cells[new_x][new_y].getObject() && cells[new_x][new_y].getObject()->get_type() == Object_Type::predator)
                return &cells[new_x][new_y];

    }
    return nullptr;
}


unsigned int Ocean::get_prey_amount()
{
    unsigned int prey_amount = 0;
    for(auto i(stuff.begin()); i != stuff.end(); ++i)
    {
        if ((*i)->get_type() == Object_Type::prey)
        {
           prey_amount++;}

    }
        return prey_amount;

}

unsigned int Ocean::get_stone_amount()
{
    unsigned int stone_amount = 0;
    for(auto i(stuff.begin()); i != stuff.end(); ++i)
    {
        if ((*i)->get_type() == Object_Type::stone)
        {
            stone_amount++;}

    }
    return stone_amount;

}

unsigned int Ocean::get_predator_amount()
{
    unsigned int predator_amount = 0;
    for(auto i(stuff.begin()); i != stuff.end(); ++i)
    {
        if ((*i)->get_type() == Object_Type::predator)
        {
            predator_amount++;}

    }
    return predator_amount;

}

void Ocean::write_results_to_file(unsigned int am1, unsigned int am2 , unsigned int am3, unsigned int it)
{
    ofstream output_file;
    ofstream output_file_graph;
    output_file.open("C:/Education/Shtanuk/tp-lab-7/info_about_objects/objects_amount.txt",ios::app);
    output_file_graph.open("C:/Education/Shtanuk/tp-lab-7/info_about_objects/for_graph.txt",ios::app);
    if (output_file.is_open() && output_file_graph.is_open())
    {

        output_file << "The amount of Preys is : " << am1 << " the iteration = "<< it << endl;
        output_file << "The amount of Predators is : " << am2 <<" the iteration = "<< it << endl;
        output_file << "The amount of Stones is : " << am3 << " the iteration = "<< it << endl;
        output_file_graph  << am1 << ':' <<  am2 << ':' << am3 << ':' << it<< ':';


    } else
        cout << "Cannot find such file";
}



void Ocean::run()
{
    for(auto i(stuff.begin()); i != stuff.end();++i)
    {
        if ((*i)-> live() == false)
        {
            deleteObjects(*i);
            stuff.erase(i++);

        }
    }
}