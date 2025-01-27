#include "raylib.h"
#include "raylib.hpp"
#include "cmath"
#include <entity.hpp>

    void entity::drawTexture(){
        DrawTextureV(this->texture, this->position, WHITE);
        return;
    }