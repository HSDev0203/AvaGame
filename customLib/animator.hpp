#include <raylib.h>
#include <iostream>
#pragma once

class Animator{
    public:
        Vector2 pos;
        Texture2D tex;
        int imageCount;
        int scale;
        Animator(Vector2 pos, Texture2D tex, int imageCount, int scale, void (*onFinished)());
        void playSpriteSheet(int speed);
        void playSpriteSheetOnce(int speed);
        void initFrame();
        
    private:
        int mFrameCounter = 0;
        int mCurrentFrame = 0;
        void (*mOnFinished)();
        bool shouldStop;
        Rectangle mFrame;

};