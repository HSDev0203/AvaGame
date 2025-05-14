#include <diamond.hpp>
#include "player.hpp"



static Texture2D gemTexture;   
static Texture2D geodeTexture;

Diamond::Diamond(Vector2 pPos){  
        value = 20;
        isGem = false;
        position = pPos;
        currentTexture = geodeTexture;
        collisionBox = {position.x, position.y, 50, 50};

    }
int Diamond::update(){
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
 void Diamond::unloadTextures(){
    UnloadTexture(gemTexture);
    UnloadTexture(geodeTexture);
}

void Diamond::loadTextures(){
    gemTexture = LoadTexture("../resources/gfx/Box.png");
    geodeTexture = LoadTexture("../resources/gfx/Zombie.png");
}
