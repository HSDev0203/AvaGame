#include <game_utils.hpp>

std::vector<Vector2> shuffle_positions(std::vector<Vector2> arr){
    srand(time(0));
    int last_index = arr.size() - 1;
    std::cout << "index" << last_index;
    while (last_index > 0){
        int rand_index = rand() % last_index;
        Vector2 temp = arr[last_index];
        arr[last_index] = arr[rand_index];
        arr[rand_index] = temp;
        last_index -= 1;
    }
    return arr;
}