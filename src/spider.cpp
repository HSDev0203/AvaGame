#include <spider.hpp>
#include "player.hpp"

// Initialize static members
Texture2D spider::gemTexture = {0};
Texture2D spider::geodeTexture = {0};

spider::spider(Vector2 pos){
    // Only load textures once for all instances
    if (gemTexture.id == 0) {
        gemTexture = LoadTexture("resources/gfx/Box.png");
    }
    if (geodeTexture.id == 0) {
        geodeTexture = LoadTexture("resources/gfx/Zombie.png");
    }
    
    value = 1;
    currentTexture = geodeTexture;
    isGem = false;
    position = pos;
    collisionBox.x = position.x;
    collisionBox.y = position.y;
    collisionBox.width = 50;
    collisionBox.height = 50;
}

int spider::update(){
    collisionBox.x = position.x;
    collisionBox.y = position.y;
    if(IsMouseButtonDown(0)){
        Rectangle mouseBox = {(float)GetMouseX(), (float)GetMouseY(), 20, 20};
        if(CheckCollisionRecs(collisionBox, mouseBox) && !isGem){
            currentTexture = gemTexture;
            isGem = true;
            return value;
        }
    }
    return 0;
}

spider::~spider(){
    // Only unload textures in the last instance
    static int instanceCount = 0;
    instanceCount++;
    if (instanceCount == 1) {  // Only one spider in the game
        UnloadTexture(gemTexture);
        UnloadTexture(geodeTexture);
        gemTexture.id = 0;
        geodeTexture.id = 0;
    }
}


