#pragma once
#include <vector>
#include "Object.h"
#include <cstring>

class LivingObject;
class Cell;

class Ocean {
    Cell** cells;
    const int width;
    const int height;
	std::vector<coord*> emptyCells;
	std::vector<LivingObject*> livingObjects;
public:
    Ocean();

    Ocean(int width, int height);

    int getHeight();

    int getWidth();

	void createObjects();

	coord* generateCoord();

    void print();

	void mainloop();

	void update();

	Cell* getCell(int x, int yl);

	Cell* getCell(coord* coordinates);

	void addObject(LivingObject* object);

	void deleteObject(LivingObject* object);

	bool isExist(int index, LivingObject* object);
};
