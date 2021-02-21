#include <stdbool.h>

bool move_on(int old_array[][4], int new_array[][4]){
    int counter = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if(old_array[i][j] == new_array[i][j] && old_array[i][j] != 0) {
                counter++;
            }
        }
    }
    if (counter == 15){
        return false;
    } return true;
}