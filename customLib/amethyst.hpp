#include "raylib.h"
#include "raylib.hpp"
#include "cmath"

#include <gem.hpp>

#pragma once

class Amethyst: public Gem
{
private:

public:
    int update();
    static void unloadTextures();
    static void loadTextures();
    Amethyst(Vector2 pos);
};