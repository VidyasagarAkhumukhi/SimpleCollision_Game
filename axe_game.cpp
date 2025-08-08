/*
 * axe_game.cpp
 * this program is a simple axe game to learn c++ fundamentals
 * noto*/

#include "raylib.h"

int main()
{
    // data type

    // float root_beer = 1.99; // float

    // double cheese_burger = 5.99; // double

    // bool shouldHaveLunch = true; // boolean

    // // braced initialization using {}, does the same thing as assessment initialization but gives it a default value if nothing is assigned, so less garbage values
    // float notRootBeer{1.99};
    // double notCheeseBurger{};
    // bool shouldHaveDinner{true};

    // // comparison ops:
    // bool equal{4 == 9};      // false
    // bool notEqual{4 != 9};   // true
    // bool less{4 < 9};        // true
    // bool greater{4 > 9};     // false
    // bool lessEqual{4 <= 9};  // true
    // bool greatEqual{4 >= 9}; // false

    int width{600}, height{600}; // int //braced initialization //window dimensions

    int circle_x{200}, circle_y{300}, circle_radius{50}; // circle co-ordinates
    // circle edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    // axe co-ordinates
    int axe_x{400}, axe_y{300}, direction{10}, axe_length{50};
    // axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    bool collision_with_axe = (b_axe_y >= u_circle_y) &&
                              (u_axe_y <= b_circle_y) &&
                              (l_axe_x <= r_circle_x) &&
                              (r_axe_x >= l_circle_x);

    InitWindow(width, height, "noto"); // initializes windows of size

    SetTargetFPS(180);
    while (!WindowShouldClose())
    {
        BeginDrawing();         // opens the window and lets raylib update in background
        ClearBackground(WHITE); // background of the window

        if (collision_with_axe)
        {
            DrawText("Game Over!", 180, 200, 50, RED);
        }
        else
        {
            // game logic begins

            // updating the edges of circle and axe as it moves
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;

            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            // update collision with axe
            collision_with_axe = (b_axe_y >= u_circle_y) &&
                                 (u_axe_y <= b_circle_y) &&
                                 (l_axe_x <= r_circle_x) &&
                                 (r_axe_x >= l_circle_x);

            DrawCircle(circle_x, circle_y, circle_radius, SKYBLUE); // creates circle with given co-ordinates and color

            // the axe (rectangles that will kill you hehe) using DrawRectangle
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

            // moving the axe
            axe_y += direction;
            if (axe_y > height || 0 > axe_y) // using OR to define the bounds
            {
                direction = -direction; // direction will be -10. thus substracting 10 when the axe hits the lower boundary
            }

            // circle right
            if (IsKeyDown(KEY_D) && circle_x < width) // IsKeyDown is used to get the input and do something when a key is pressed down
            {
                circle_x += 10;
            }

            // circle left
            if (IsKeyDown(KEY_A) && 0 < circle_x) // using AND operator to keep the circle inbounds
            {
                circle_x -= 10;
            }

            // circle up
            if (IsKeyDown(KEY_W) && 0 < circle_y)
            {
                circle_y -= 10;
            }

            // circle down
            if (IsKeyDown(KEY_S) && circle_y < height)
            {
                circle_y += 10;
            }
            // game logic ends
        }
        EndDrawing(); // ends the window and raylib work in background
    }
}