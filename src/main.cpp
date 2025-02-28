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
#include "iostream"
#include <spider.hpp>
#include <amethyst.hpp>
#include <player.hpp>
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

void level_1(){
    player pmain;
    amethyst a[] = {
        Vector2{100, 100}, Vector2{200, 100},
        Vector2{100, 200}, Vector2{200, 200},
        Vector2{100, 300}, Vector2{200, 300},

    };
    /*spider s[] = {
        Vector2{300, 100}
    };*/
    pmain.cash = 0;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        for(int i = 0; i < int(sizeof(a)); i++){
            pmain.cash += a[i].update();
        }
        /*
        for(int i = 0; i < int(sizeof(a)); i++){
            pmain.lives -= s[i].update();
        }
        */

        Rectangle mouseBox = {float(GetMouseX()), float(GetMouseY()), 20, 20};
       //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangleRec(mouseBox, RED);

              for(int i = 0; i < int(sizeof(a)); i++){ 
                a[i].drawCollisionBox();
                a[i].drawTexture();
            }
            /*
              for(int i = 0; i < int(sizeof(s)); i++){ 
                s[i].drawCollisionBox();
                s[i].drawTexture();
            }
                */
            std::cout << pmain.cash; 
            
            DrawText(TextFormat("lives: %i", pmain.lives), 300, 300,20, RED);
            DrawText(TextFormat("cash: %i", pmain.cash), 300, 300,20, RED);
        EndDrawing();
        //----------------------------------------------------------------------------------/** */
    }

    for(int i = 0; i < int(sizeof(a)) - 1; i++){
        a[i].~amethyst();
    }
    /*
    for(int i = 0; i < int(sizeof(s)) - 1; i++){
        s[i].~spider();
    }
        */
    // De-Initialization
    //--------------------------------------------------------------------------------------
}


int main(void)
{

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;



    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    level_1();

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}