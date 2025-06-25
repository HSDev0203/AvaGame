#include "button.hpp"

Button::Button(Rectangle pRec, Color pCol, void (*pCallBack)()){
    rec = pRec;
    col = pCol;
    mCallBack = pCallBack;
};

void Button::draw(){
    DrawRectangleRec(rec, col);
}
void Button::update(){
    if(IsMouseButtonPressed(0)){
        if(CheckCollisionRecs(rec, Rectangle{float(GetMouseX()), float(GetMouseY()), 20, 20})){
            mCallBack();
        }
    }
}