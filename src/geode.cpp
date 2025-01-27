#include "raylib.h"
#include "raylib.hpp"
#include "cmath"
#include <geode.hpp>

    void entity::drawTexture(){
        DrawTextureV(this->texture, this->position, WHITE);
        return;
    }