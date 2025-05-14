#include <game_utils.hpp>
#include "iostream"

std::vector<Vector2> shufflePositions(std::vector<Vector2> arr){
    srand(time(0));
    int lastIndex = arr.size() - 1;
    
    while (lastIndex > 0){
        int randIndex = rand() % lastIndex;
        Vector2 temp = arr[lastIndex];
        arr[lastIndex] = arr[randIndex];
        arr[randIndex] = temp;
        lastIndex -= 1;
    }
    return arr;
}

std::vector<Vector2> generatePositions(std::vector<Vector2> arr, int size, int offset_x = 0, int offset_y = 0){
    int x = 1;
    int y = 1; 
    
    for(int i = pow(size, 2); i > 0; i -= 1){
        Vector2 v;
        v.x = (x * 100) + offset_x;
        v.y = (y * 100) + offset_y;
        if(x >= size){ y++;  x = 1;}else{x++;}
        arr.push_back(v);
    }
    arr = shufflePositions(arr);
    return arr;
}
