#include <raylib.h>
#include <iostream>
#pragma once

class Animator{
    public:
        Vector2 pos;
        Texture2D tex;
        int imageCount;
        Animator(Vector2 pos, Texture2D tex, int imageCount);
        void playSpriteSheet(int speed);
        void update();
        void initFrame();

    private:
        int frameCounter = 0;
        int currentFrame;
        Rectangle Frame;

};