#include <animator.hpp>


Animator::Animator(Vector2 pPos, Texture2D pTex, int pImageCount, int pScale = 1){  
    pos = pPos;
    tex = pTex;  
    imageCount = pImageCount;
    scale = pScale;
}
void Animator::update(int pSpeed){
    mFrameCounter++;
    if(mFrameCounter >= (60/pSpeed)){
        mFrameCounter = 0;
        mCurrentFrame++;
        if (mCurrentFrame > imageCount - 1){
            mCurrentFrame = 0;
        }

        mFrame.x = (float)mCurrentFrame*(float)tex.width/imageCount;
    };
}
void Animator::initFrame(){
    mFrame = { 0.0f, 0.0f, (float)tex.width/imageCount, (float)tex.height};
}

void Animator::playSpriteSheet(){
    DrawTexturePro(tex, mFrame, Rectangle{0.0f, 0.0f, mFrame.width * scale, mFrame.height * scale}, pos, 0, WHITE );
}




