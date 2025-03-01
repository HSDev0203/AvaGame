#include "raylib.h"
#include "raylib.hpp"
#include "cmath"

#include <gem.hpp>

#pragma once

class amethyst: public gem
{
private:

public:
    int update();
    static void unloadTextures();
    static void loadTextures();
    amethyst(Vector2 pos);
};