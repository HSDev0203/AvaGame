#include <animator.hpp>


Animator::Animator(Vector2 pos, Texture2D tex, int imageCount){  
    this->pos = pos;
    this->tex = tex;  
    this->imageCount = imageCount;
}
void Animator::update(int speed){
    frameCounter++;
    if(frameCounter >= (60/speed)){
        frameCounter = 0;
        currentFrame++;
        if (currentFrame > imageCount - 1){
            currentFrame = 0;
        }

        Frame.x = (float)currentFrame*(float)tex.width/imageCount;
        std::cout << "Frame.x: " << Frame.x << "\n";
        std::cout << "tex.width: " << tex.width << "\n";
        std::cout << "tex.height: " << tex.height << "\n";
        std::cout << "Texture ID: " << tex.id << "\n";
    };
}
void Animator::initFrame(){
    Frame = { 0.0f, 0.0f, (float)tex.width/imageCount, (float)tex.height};
}

void Animator::playSpriteSheet(){
    DrawTextureRec(tex, Frame, pos, WHITE);
}




