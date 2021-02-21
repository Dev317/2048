#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "move_left_one_row.h"
#include "move_right_one_row.h"
#include "rotate_90.h"
#include "move_on.h"
#include "generate_random.h"

int main(void) {
    srand(time(0));
    int array[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            
            int r = rand() % 4;
            while (r == 0) {
                r = rand() % 4;
            }
            array[i][j] = (int) pow(2,r);
        }
    }
    

    printf("Matrix Generated: \n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", array[i][j]);
        } printf("\n");
    }

    int old_array[4][4];

    do {
        char c;
        printf("Enter move (U, D, L or R): ");
        scanf(" %c", &c);

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                old_array[i][j] = array[i][j];
            }
        }

        if (c == 'L') {
            for (int i = 0; i < 4; i++) {
                int temp_row_array[4];
                for (int j = 0; j < 4; j++) {
                    temp_row_array[j] = array[i][j];
                }
                move_left_one_row(temp_row_array, 4);
                for (int j = 0; j < 4; j++) {
                    array[i][j] = temp_row_array[j];
                }
            }
        } else if (c == 'R') {
            for (int i = 0; i < 4; i++) {
                int temp_row_array[4];
                for (int j = 0; j < 4; j++) {
                    temp_row_array[j] = array[i][j];
                }
                move_right_one_row(temp_row_array, 4);
                for (int j = 0; j < 4; j++) {
                    array[i][j] = temp_row_array[j];
                }
            }
        } else if (c == 'U') {
            rotate_90_clock_wise(array,4);

            for (int i = 0; i < 4; i++) {
                int temp_row_array[4];
                for (int j = 0; j < 4; j++) {
                    temp_row_array[j] = array[i][j];
                }
                move_right_one_row(temp_row_array, 4);
                for (int j = 0; j < 4; j++) {
                    array[i][j] = temp_row_array[j];
                }
            }

            rotate_90_anti_clock_wise(array,4);
        } else if (c == 'D') {
            rotate_90_clock_wise(array,4);
            
            for (int i = 0; i < 4; i++) {
                int temp_row_array[4];
                for (int j = 0; j < 4; j++) {
                    temp_row_array[j] = array[i][j];
                }
                move_left_one_row(temp_row_array, 4);
                for (int j = 0; j < 4; j++) {
                    array[i][j] = temp_row_array[j];
                }
            }
            rotate_90_anti_clock_wise(array,4);
        }

        printf("------\n");
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                printf("%d ", array[i][j]);
            } printf("\n");
        }

    } while(move_on(old_array, array) && generate_random(array));

    printf("Result: \n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", array[i][j]);
        } printf("\n");
    }
}