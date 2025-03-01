#include <spider.hpp>
#include "player.hpp"



static Texture2D gemTexture;   
static Texture2D geodeTexture;

    spider::spider(Vector2 pos){  
        value = -1;
        isGem = false;
        position = pos;
        currentTexture = geodeTexture;
        collisionBox = {position.x, position.y, 50, 50};

    }
int spider::update(){
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
 void spider::unloadTextures(){
    UnloadTexture(gemTexture);
    UnloadTexture(geodeTexture);
}

void spider::loadTextures(){
    gemTexture = LoadTexture("../resources/gfx/scarfy.png");
    geodeTexture = LoadTexture("../resources/gfx/Gun.png");
}

