/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Example complexity rating: [★☆☆☆] 1/4
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute 'raylib_compile_execute' script
*   Note that compiled executable is placed in the same folder as .c file
*
*   To test the examples on Web, press F6 and execute 'raylib_compile_execute_web' script
*   Web version of the program is generated in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2025 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
#include "raylib.h"
#include "vector"
#include "iostream"
#include "random" 
#include <spider.hpp>
#include <amethyst.hpp>
#include <diamond.hpp>
#include <player.hpp>
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------




int main(void)
{

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;



    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    player pmain;
    pmain.cash = 0;
    
    amethyst::loadTextures();
    diamond::loadTextures();
    
    amethyst a[] = {
        amethyst({Vector2{100, 100}}),
        amethyst(Vector2{100, 200}),
        amethyst(Vector2{100, 300}),
    };
    diamond d[] ={
        diamond(Vector2{200, 100}),
        diamond(Vector2{200, 200}),    
        diamond(Vector2{200, 300}),    
    };
    int diamondCount = sizeof(d) / sizeof(d[0]);
    int amethystCount = sizeof(a) / sizeof(a[0]);
    
    spider::loadTextures();
    spider s[] = {
        spider(Vector2{300, 100}),
    };
    int spiderCount = sizeof(s) / sizeof(s[0]);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        for(int i = 0; i < amethystCount; i++){
            pmain.cash += a[i].update();
        }
        for(int i = 0; i < diamondCount; i++){
            pmain.cash += d[i].update();
        }
        for(int i = 0; i < spiderCount; i++){
            pmain.lives += s[i].update();
        }

        Rectangle mouseBox = {float(GetMouseX()), float(GetMouseY()), 20, 20};
       //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangleRec(mouseBox, RED);
           
            for(int i = 0; i < amethystCount; i++){ 
                a[i].drawCollisionBox();
                a[i].drawTexture();
            }
            for(int i = 0; i < diamondCount; i++){ 
                d[i].drawCollisionBox();
                d[i].drawTexture();
            }
            for(int i = 0; i < spiderCount; i++){ 
                s[i].drawCollisionBox();
                s[i].drawTexture();
            }
            
            DrawText(TextFormat("lives: %i", pmain.lives), 400, 300,20, RED);
            DrawText(TextFormat("cash: %i", pmain.cash), 300, 300,20, RED);
        EndDrawing();
        //----------------------------------------------------------------------------------/** */
    }
    amethyst::unloadTextures();
    spider::unloadTextures();
    diamond::unloadTextures();
    /*
    for(int i = 0; i < int(sizeof(s)) - 1; i++){
        s[i].~spider();
    }
        */
    // De-Initialization
    //--------------------------------------------------------------------------------------

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}