#include <animator.hpp>


Animator::Animator(Vector2 pos, Texture2D tex, int imageCount){  
    this->pos = pos;
    this->tex = tex;  
    this->imageCount = imageCount;
}
void Animator::update(){
    frameCounter++;
}
void Animator::initFrame(){
    Frame = { (float)tex.width/imageCount, 0.0f, (float)tex.width/imageCount, (float)tex.height};
}

void Animator::playSpriteSheet(int speed){

    if(frameCounter >= (60/speed)){
        frameCounter = 0;
        currentFrame++;
        if (currentFrame > imageCount){
            currentFrame = 1;
        }

        Frame.x = (float)currentFrame*(float)tex.width/imageCount;
        std::cout << "Frame.x: " << Frame.x << "\n";
        std::cout << "tex.width: " << tex.width << "\n";
    }
    DrawTextureRec(tex, Rectangle{Frame.x, 0.0, float(tex.width)/imageCount, float(tex.height)}, pos, WHITE);
}




