#include "raylib.h"
#include "raylib.hpp"
#include "cmath"

#define GEM_HPP

#pragma once

class gem
{

public:
    void drawTexture();
    void drawCollisionBox();

protected:

    int value;
    Texture2D geodeTexture;
    Texture2D gemTexture;
    Texture2D currentTexture;
    Vector2 position;
    Rectangle collisionBox;

};