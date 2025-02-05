#include "raylib.h"
#include "raylib.hpp"
#include "cmath"
#include <gem.hpp>



void gem::drawTexture(){
    DrawTextureV(this->currentTexture, this->position, WHITE);
    return;
}

void gem::drawCollisionBox(){
    DrawRectangle(collisionBox.x, collisionBox.y, collisionBox.width, collisionBox.height, RED);
}