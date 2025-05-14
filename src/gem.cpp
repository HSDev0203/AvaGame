#include "raylib.h"
#include "raylib.hpp"
#include "cmath"
#include <gem.hpp>



void Gem::drawTexture(){
    DrawTextureV(currentTexture, position, WHITE);
    return;
}

void Gem::drawCollisionBox(){
    DrawRectangle(collisionBox.x, collisionBox.y, collisionBox.width, collisionBox.height, RED);
}