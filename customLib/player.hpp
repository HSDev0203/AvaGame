#include <raylib.h>
#include <iostream>
#pragma once


class Player{
    public:
        void update();
        int cash, cashGoal, lives = 3, level = 1;
};
