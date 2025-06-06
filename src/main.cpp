
#include "raylib.h"
#include "vector"
#include "iostream"
#include "random" 
#include <spider.hpp>
#include <amethyst.hpp>
#include <diamond.hpp>
#include <player.hpp>
#include <game_utils.hpp>
#include <animator.hpp>
#include <button_functions.hpp>
#include <button.hpp>
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
Player pmain;

std::vector<Vector2> p;
std::string level = "level_1";

//generate positions in a square grid



std::vector<Amethyst> a;  

std::vector<Diamond> d;

std::vector<Spider> s;

std::vector<Animator> anim;

Texture2D main_screen;

int level_cash_req;
int level_seconds;
int framesCounter = 0;

int seconds_elapsed;
int seconds_left;
bool init = true;

void loadLevel(){
    if(level == "level_1" && init == true){
        
        anim = {Animator(Vector2{0,0}, main_screen, 87, 10)};
        for(int i = 0; i < (int)anim.size(); i++){ 
            anim[i].initFrame();
        }

        p = generatePositions(p, 7, 0, 0);
        p = shufflePositions(p);
        a = {p[0]}; 
        init = false;
    }
    if(level == "level_2" && init == true){
        p = generatePositions(p, 81, 100, 0);
        p = shufflePositions(p);
        a = {p[0]};
        init = false;
    }
}

void updateLevel(){
    if(level == "level_1"){
        framesCounter++;
        seconds_elapsed = (framesCounter / 60);
        seconds_left = level_seconds - seconds_elapsed;

        for(int i = 0; i < (int)a.size(); i++){
            pmain.cash += a[i].update();
        }
        for(int i = 0; i < (int)d.size(); i++){
            pmain.cash += d[i].update();
        }
        for(int i = 0; i < (int)s.size(); i++){
            pmain.lives += s[i].update();
        }
        for(int i = 0; i < (int)anim.size(); i++){
            anim[i].update(10);
        }
       
        
    }
    else if(level == "level_2"){
        framesCounter++;
        seconds_elapsed = (framesCounter / 60);
        seconds_left = level_seconds - seconds_elapsed;
        
        for(int i = 0; i < (int)a.size(); i++){
            pmain.cash += a[i].update();
        }
        for(int i = 0; i < (int)d.size(); i++){
            pmain.cash += d[i].update();
        }
        for(int i = 0; i < (int)s.size(); i++){
            pmain.lives += s[i].update();
        }
        for(int i = 0; i < (int)anim.size(); i++){
            anim[i].update(1);
        }
    } 
}
void drawLevel(){

    Rectangle mouseBox = {float(GetMouseX()) - 10, float(GetMouseY()) - 10, 20, 20};

    BeginDrawing();
    DrawRectangleRec(mouseBox, RED);
   
    for(int i = 0; i < (int)a.size(); i++){ 
        a[i].drawCollisionBox();
        a[i].drawTexture();
    }
    for(int i = 0; i < (int)d.size(); i++){ 
        d[i].drawCollisionBox();
        d[i].drawTexture();
    }
    for(int i = 0; i < (int)s.size(); i++){ 
        s[i].drawCollisionBox();
        s[i].drawTexture();
    }
    for(int i = 0; i < (int)p.size(); i++){
        DrawRectangle(p[i].x + 50, p[i].y + 50, 50, 50, RED );
    }
    for(int i = 0; i < (int)anim.size(); i++){
        anim[i].playSpriteSheet();
    }

    

    ClearBackground(RAYWHITE);
    
    DrawText(TextFormat("lives: %i", pmain.lives), 500, 800,20, RED);
    DrawText(TextFormat("cash: %i", pmain.cash), 400, 800,20, RED);
    DrawText(TextFormat("time: %i", seconds_elapsed), 300, 800,20, RED);
    EndDrawing();

}

int main(void)
{

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 850;
    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
  
    main_screen = LoadTexture("../resources/gfx/start_screen-sheet.png");

    Amethyst::loadTextures();
    Diamond::loadTextures();
    Spider::loadTextures();
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    // Detect window close button or ESC key
       
    while(!WindowShouldClose()){
        loadLevel(); 
        updateLevel();
        drawLevel();
    }
    Amethyst::unloadTextures();
    Spider::unloadTextures();
    Diamond::unloadTextures();
    UnloadTexture(main_screen);
    // De-Initialization
    //--------------------------------------------------------------------------------------

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}