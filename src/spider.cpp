#include <spider.hpp>
#include "player.hpp"


spider::spider(Vector2 pos){
        value = 1;
        gemTexture = LoadTexture("../resources/gfx/Box.png");
        geodeTexture = LoadTexture("../resources/gfx//Zombie.png");
        currentTexture = geodeTexture;
        isGem = false;
        position = pos;
        collisionBox = {position.x, position.y, 50, 50};
    }
int spider::update(){
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
spider::~spider(){
    UnloadTexture(gemTexture);
    UnloadTexture(geodeTexture);
    UnloadTexture(currentTexture);
}


