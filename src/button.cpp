#include "button.hpp"

button::button(Rectangle rec, Color col, void (*callback)()){
    button::rec = rec;
    button::col = col;
    button::callback = callback;
};

void button::draw(){
    DrawRectangleRec(rec, col);
}
void button::update(){
    if(IsMouseButtonPressed(0)){
        if(CheckCollisionRecs(rec, Rectangle{float(GetMouseX()), float(GetMouseY()), 20, 20})){
            callback();
        }
    }
}