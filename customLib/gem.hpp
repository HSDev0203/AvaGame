#include "raylib.h"
#include "raylib.hpp"
#include "cmath"

#pragma once

class Gem
{

public:
    void drawTexture();
    void drawCollisionBox();
    Vector2 position;
    
protected:
    int value;
    bool isGem;
    Texture2D currentTexture;
    Rectangle collisionBox;
};