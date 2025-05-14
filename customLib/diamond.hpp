#include "raylib.h"
#include "raylib.hpp"
#include "cmath"

#include <gem.hpp>

#pragma once

class Diamond: public Gem
{
private:

public:
    int update();
    static void unloadTextures();
    static void loadTextures();
    Diamond(Vector2 pos);
};