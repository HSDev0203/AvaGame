#include <amethyst.hpp>
#include "player.hpp"

static Texture2D gemTexture;   
static Texture2D geodeTexture;

Amethyst::Amethyst(Vector2 pPos){  
        value = 10;
        isGem = false;
        position = pPos;
        currentTexture = geodeTexture;
        collisionBox = {position.x + 50, position.y + 50, 50, 50};
    }
int Amethyst::update(){
    if(IsMouseButtonPressed(0)){
        if(CheckCollisionRecs(collisionBox, Rectangle{float(GetMouseX()), float(GetMouseY()), 20, 20}) && !isGem){
            currentTexture = gemTexture;
            isGem = true;
            return value;
        }
    }
    return 0;
}

void Amethyst::unloadTextures(){
    UnloadTexture(gemTexture);
    UnloadTexture(geodeTexture);
}

void Amethyst::loadTextures(){
    gemTexture = LoadTexture("../resources/gfx/Box.png");
    geodeTexture = LoadTexture("../resources/gfx/Zombie.png");
}
