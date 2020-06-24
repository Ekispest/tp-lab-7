#pragma once

#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common_settings.h"


class Stone: public Object{
public:
    explicit Stone(Cell* cell);
    ~Stone() override = default;
    bool live () override;
    char get_symbol() override;
    void reproduction() override;
    void move() override;
};