#include "raylib.h"
#include "raylib.hpp"
#include "cmath"

#include <gem.hpp>

#pragma once

class spider: public gem
{
private:

public:
    int update();
    static void unloadTextures();
    static void loadTextures();
    spider(Vector2 pos);
};