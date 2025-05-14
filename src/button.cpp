#include "button.hpp"

Button::Button(Rectangle pRec, Color pCol, void (*pCallBack)()){
    Button::rec = pRec;
    Button::col = pCol;
    Button::CallBack = pCallBack;
};

void Button::draw(){
    DrawRectangleRec(rec, col);
}
void Button::update(){
    if(IsMouseButtonPressed(0)){
        if(CheckCollisionRecs(rec, Rectangle{float(GetMouseX()), float(GetMouseY()), 20, 20})){
            CallBack();
        }
    }
}