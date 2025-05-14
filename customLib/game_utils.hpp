#pragma once

#include "raylib.h"
#include "iostream"
#include "random"

std::vector<Vector2> shufflePositions(std::vector<Vector2>);
std::vector<Vector2> generatePositions(std::vector<Vector2> arr, int size, int offset_x, int offset_y);