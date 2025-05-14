#include "raylib.h"

class Button{
    public:
        Rectangle rec;
        Color col;
        Button(Rectangle pRec, Color pCol, void (*pCallBack)());
        void draw();
        void update();
    private:
        void (*CallBack)();
};