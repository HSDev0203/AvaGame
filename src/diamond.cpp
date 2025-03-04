#include <diamond.hpp>
#include "player.hpp"



static Texture2D gemTexture;   
static Texture2D geodeTexture;

diamond::diamond(Vector2 pos){  
        value = 20;
        isGem = false;
        position = pos;
        currentTexture = geodeTexture;
        collisionBox = {position.x, position.y, 50, 50};

    }
int diamond::update(){
    collisionBox.x = position.x;
    collisionBox.y = position.y;
    if(IsMouseButtonPressed(0)){
        if(CheckCollisionRecs(collisionBox, Rectangle{float(GetMouseX()), float(GetMouseY()), 20, 20}) && !isGem){
            currentTexture = gemTexture;
            isGem = true;
            return value;
        }
    }
    return 0;
}
 void diamond::unloadTextures(){
    UnloadTexture(gemTexture);
    UnloadTexture(geodeTexture);
}

void diamond::loadTextures(){
    gemTexture = LoadTexture("../resources/gfx/Box.png");
    geodeTexture = LoadTexture("../resources/gfx/Zombie.png");
}
