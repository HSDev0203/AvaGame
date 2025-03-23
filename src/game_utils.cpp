#include <game_utils.hpp>
#include "iostream"

std::vector<Vector2> shuffle_positions(std::vector<Vector2> arr){
    srand(time(0));
    int last_index = arr.size() - 1;
    
    while (last_index > 0){
        int rand_index = rand() % last_index;
        Vector2 temp = arr[last_index];
        arr[last_index] = arr[rand_index];
        arr[rand_index] = temp;
        last_index -= 1;
    }
    return arr;
}

std::vector<Vector2> generate_positions(std::vector<Vector2> arr, int size, int offset_x = 0, int offset_y = 0){
    int x = 1;
    int y = 1; 
    
    for(int i = pow(size, 2); i > 0; i -= 1){
        Vector2 v;
        v.x = (x * 100) + offset_x;
        v.y = (y * 100) + offset_y;
        if(x >= size){ y++;  x = 1;}else{x++;}
        arr.push_back(v);
    }
    arr = shuffle_positions(arr);
    return arr;
}