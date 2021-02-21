#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

bool generate_random(int array[][4]) {
    srand(time(0));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (array[i][j] == 0) {
                int r = rand() % 4;
                while (r == 0) {
                    r = rand() % 4;
                }
                array[i][j] = (int) pow(2,r);
            }
        }
    }
    return true;
}