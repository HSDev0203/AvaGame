#include "raylib.h"
#include "raylib.hpp"
#include "cmath"

#include <gem.hpp>

#pragma once

class spider: public gem
{
private:
    static Texture2D geodeTexture;
    static Texture2D gemTexture;
public:
    spider(Vector2 pos);
    int update();
    ~spider();

};