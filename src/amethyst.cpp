#include <amethyst.hpp>
#include "player.hpp"

amethyst::amethyst(Vector2 pos){  
        gemTexture = LoadTexture("../resources/gfx/Box.png");
        geodeTexture = LoadTexture("../resources/gfx/Box.png");
        value = 10;
        currentTexture = geodeTexture;
        isGem = false;
        position = pos;
        collisionBox = {position.x, position.y, 50, 50};

    }
int amethyst::update(){
    collisionBox.x = position.x;
    collisionBox.y = position.y;
    if(IsMouseButtonDown(0)){
        if(CheckCollisionRecs(collisionBox, Rectangle{float(GetMouseX()), float(GetMouseY()), 20, 20}) && isGem == false){
            currentTexture = gemTexture;
            isGem = true;
            return value;
        }
    }
    return 0;
}
amethyst::~amethyst(){
    UnloadTexture(gemTexture);
    UnloadTexture(geodeTexture);
    UnloadTexture(currentTexture);
}


