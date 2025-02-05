#include <amethyst.hpp>



amethyst::amethyst(Vector2 pos){
        value = 10;
        gemTexture = LoadTexture("../resources/gfx/Box.png");
        geodeTexture = LoadTexture("../resources/gfx//Zombie.png");
        currentTexture = geodeTexture;
        position = pos;
        collisionBox = {position.x, position.y, 50, 50};
    }
amethyst::~amethyst(){
    UnloadTexture(gemTexture);
    UnloadTexture(geodeTexture);
    UnloadTexture(currentTexture);
}


