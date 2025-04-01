#include <amethyst.hpp>
#include "player.hpp"

static Texture2D gemTexture;   
static Texture2D geodeTexture;

amethyst::amethyst(Vector2 pos){  
        value = 10;
        isGem = false;
        position = pos;
        currentTexture = geodeTexture;
        collisionBox = {position.x + 50, position.y + 50, 50, 50};
    }
int amethyst::update(){
    if(IsMouseButtonPressed(0)){
        if(CheckCollisionRecs(collisionBox, Rectangle{float(GetMouseX()), float(GetMouseY()), 20, 20}) && !isGem){
            currentTexture = gemTexture;
            isGem = true;
            return value;
        }
    }
    return 0;
}

void amethyst::unloadTextures(){
    UnloadTexture(gemTexture);
    UnloadTexture(geodeTexture);
}

void amethyst::loadTextures(){
    gemTexture = LoadTexture("../resources/gfx/Box.png");
    geodeTexture = LoadTexture("../resources/gfx/Zombie.png");
}
