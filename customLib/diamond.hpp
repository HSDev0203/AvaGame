#include "raylib.h"
#include "raylib.hpp"
#include "cmath"

#include <gem.hpp>

#pragma once

class diamond: public gem
{
private:

public:
    int update();
    static void unloadTextures();
    static void loadTextures();
    diamond(Vector2 pos);
};