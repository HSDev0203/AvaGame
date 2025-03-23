#include <raylib.h>
#include <iostream>
#pragma once


class player{
    public:
        void update();
            
        int cash;
        int cashGoal;
        int lives = 3;
        int level = 1;
};
