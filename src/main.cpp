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
std::string level = "title_screen";

//generate positions in a square grid



std::vector<Amethyst> a;  

std::vector<Diamond> d;

std::vector<Spider> s;

Texture2D transitionSheet;

Texture2D mainScreenSheet;

Animator transitionAnim = Animator(Vector2{0,0}, transitionSheet, 50, 10, nullFunction);

Animator mainAnim = Animator(Vector2{0,0}, mainScreenSheet, 87, 10, nullFunction); 


int level_cash_req;
int level_seconds;
int framesCounter = 0;

int seconds_elapsed;
int seconds_left;
bool init = true;


void switchLevel(std::string level){
    
}

void loadLevel(){
    if (level == "title_screen" && init == true){

        transitionAnim = Animator(Vector2{0,0}, transitionSheet, 50, 10, setLevelTest);
        mainAnim = Animator(Vector2{0,0}, mainScreenSheet, 87, 10, nullFunction); 

        transitionAnim.initFrame();
        mainAnim.initFrame();

        init = false;
    }
    if(level == "level_1" && init == true){
        
        mainAnim.initFrame();
        transitionAnim.initFrame();

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
    if(level == "test" && init == true){
        
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
        
    }
    if(level == "level_2"){
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
    }

    if(level == "title_screen"){
        framesCounter++;
        seconds_elapsed = (framesCounter / 60);
        seconds_left = level_seconds - seconds_elapsed;
    
    }

    if(level == "test"){
        framesCounter++;
        seconds_elapsed = (framesCounter / 60);
        seconds_left = level_seconds - seconds_elapsed;
        
    }

}
void drawLevel(){

    BeginDrawing();
    
    if(level == "level_1"){
        
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
        DrawText(TextFormat("lives: %i", pmain.lives), 500, 800,20, RED);
        DrawText(TextFormat("cash: %i", pmain.cash), 400, 800,20, RED);
        DrawText(TextFormat("time: %i", seconds_elapsed), 300, 800,20, RED);

    }

    if(level == "level_2"){
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

    }
    
    if(level == "title_screen"){
        mainAnim.playSpriteSheet(30);
        if(IsKeyPressed(KEY_ENTER)){
            init = true;
        }
        DrawText("Press Enter to Start!", 300, 800,20, PURPLE);

    }
    if(level == "test"){
    }

    ClearBackground(RAYWHITE);
    EndDrawing();

}

int main(void)
{

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 850;
    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
  
    mainScreenSheet = LoadTexture("../resources/gfx/start_screen-sheet.png");
    transitionSheet = LoadTexture("../resources/gfx/transition.png");

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
    UnloadTexture(mainScreenSheet);
    UnloadTexture(transitionSheet);
    // De-Initialization
    //--------------------------------------------------------------------------------------

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}