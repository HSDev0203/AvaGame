#include "raylib.h"

class button{
    public:
        Rectangle rec;
        Color col;
        button(Rectangle rec, Color col, void (*callback)());
        void draw();
        void update();
    private:
        void (*callback)();
};