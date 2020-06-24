#pragma once
#include <iostream>
#include <time.h>


typedef size_t coord_t;

struct Pair
        {
            coord_t x; // 0..M-1
            coord_t y; // 0..N-1

        };

const size_t N = 20;
const size_t M = 50;

const int Life_Time_Prey = 10;
const int Life_Time_Predator = 20;
const int Life_Time_Stone = 1000;
const int Its_time_to_eat = 50;