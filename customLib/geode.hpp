#include "raylib.h"
#include "raylib.hpp"
#include "cmath"
#include <entity.hpp>

#pragma once

class geode : public entity
{

public:
    
    void drawTexture();

    geode::geode(Vector2 position, Vector2 texture){
        this->texture = LoadTexture("../resources/gfx/Box.png");
    }
};