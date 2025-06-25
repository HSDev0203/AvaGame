#include <animator.hpp>
#include <game_utils.hpp>

Animator::Animator(Vector2 pPos, Texture2D pTex, int pImageCount, int pScale = 1, void (*pOnFinished)() = nullFunction){  
    pos = pPos;
    tex = pTex;  
    imageCount = pImageCount;
    scale = pScale;
    mOnFinished = pOnFinished;
}
void Animator::playSpriteSheet(int pSpeed){
    mFrameCounter++;
    if(mFrameCounter >= (60/pSpeed)){
        mFrameCounter = 0;
        mCurrentFrame++;
        if (mCurrentFrame > imageCount - 1){
            mCurrentFrame = 0;
            mOnFinished();
        }

        mFrame.x = (float)mCurrentFrame*(float)tex.width/imageCount;
    };

    DrawTexturePro(tex, mFrame, Rectangle{0.0f, 0.0f, mFrame.width * scale, mFrame.height * scale}, pos, 0, WHITE );
}
void Animator::initFrame(){
    mFrame = { 0.0f, 0.0f, (float)tex.width/imageCount, (float)tex.height};
}

void Animator::playSpriteSheetOnce(int pSpeed){
    mFrameCounter++;
    if(mFrameCounter >= (60/pSpeed)){
        mFrameCounter = 0;
        mCurrentFrame++;
        if (mCurrentFrame > imageCount - 1){
            mOnFinished();
            mFrame = {0.0f, 0.0f, 0.0f, 0.0f};
        }

        mFrame.x = (float)mCurrentFrame*(float)tex.width/imageCount;
    };

    DrawTexturePro(tex, mFrame, Rectangle{0.0f, 0.0f, mFrame.width * scale, mFrame.height * scale}, pos, 0, WHITE );
}





