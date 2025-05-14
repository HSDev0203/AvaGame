#include <raylib.h>
#include <iostream>
#pragma once

class Animator{
    public:
        Vector2 pos;
        Texture2D tex;
        int imageCount;
        Animator(Vector2 pos, Texture2D tex, int imageCount);
        void playSpriteSheet();
        void update(int speed);
        void initFrame();

    private:
        int mFrameCounter = 0;
        int mCurrentFrame;
        Rectangle mFrame;

};