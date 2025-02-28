#include <raylib.h>
#include <iostream>
#pragma once


class player{
    public:
        void update();
            
        int cash;
        int lives = 3;
};
