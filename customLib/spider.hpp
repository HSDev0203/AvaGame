#include "raylib.h"
#include "raylib.hpp"
#include "cmath"

#include <gem.hpp>

#pragma once

class Spider: public Gem
{
private:

public:
    int update();
    static void unloadTextures();
    static void loadTextures();
    Spider(Vector2 pos);
};