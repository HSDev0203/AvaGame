#include "raylib.h"
#include "raylib.hpp"
#include "cmath"

#pragma once

class entity
{

public:
    Vector2 position;

    Texture2D texture;
    
    void drawTexture();

    entity(Vector2 pos, Texture2D text){
        position = pos;
        texture = text;
    }
};