#pragma once

#include "raylib.h"
#include "iostream"
#include "random"

std::vector<Vector2> shuffle_positions(std::vector<Vector2>);
std::vector<Vector2> generate_positions(std::vector<Vector2> arr, int size, int offset_x, int offset_y);