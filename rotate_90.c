void rotate_90_clock_wise (int array[][4], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int temp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = temp;
        }
    }

    int half_size = size / 2;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < half_size; j++) {
            int temp = array[i][j];
            array[i][j] = array[i][size - 1 - j];
            array[i][size - 1 - j] = temp;
        }
    }
}

void rotate_90_anti_clock_wise (int array[][4], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int temp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = temp;
        }
    }

    int half_size = size / 2;

    for (int i = 0; i < half_size; i++) {
        for (int j = 0; j < size; j++) {
            int temp = array[i][j];
            array[i][j] = array[size - 1 - i][j];
            array[size - 1 - i][j] = temp;
        }
    }
}