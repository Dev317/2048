void zero_not_at_first_index(int array[], int size, int index_contains_zero) {
    int prev_term = array[index_contains_zero - 1];
    int temp_index = 0;
    int counter = 0;
    for (int i = index_contains_zero + 1; i < size; i++) {
        if (array[i] == prev_term && array[i + 1] == 0) {
            temp_index = i;
            counter++;
            break;
        }
    }

    if (counter > 0) {
        array[index_contains_zero - 1] *= 2;
        if (temp_index != 0) {
            array[index_contains_zero] = array[temp_index + 1];
            array[temp_index] = 0;
            array[temp_index + 1] = 0;
        } else {
            array[temp_index] = 0;
        }
    }
}

void zero_at_first_index(int array[],int size) {
    int non_zero_counter = 0;
    int k = 1;
    int index[k];
    for (int i = 1; i < size; i++) {
        if (array[i] != 0) {
            non_zero_counter++;
            index[k - 1] = i;
            k++;
        }
    }
    if (non_zero_counter == 1) {
        array[0] = array[index[0]];
        array[index[0]] = 0;
    } else if (array[index[0]] == array[index[1]]) {
        array[0] = 2 * array[index[0]];
        array[index[0]] = 0;
        array[index[1]] = 0;
    }
}

void move_left_one_row(int array[], int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == array[i + 1] && array[i + 1] != 0) {
            array[i] = 2 * array[i];
            for (int j = i + 1; j < size; j++) {
                array[j] = array[j + 1];
            }
            array[size - 1] = 0;
        } else if (array[i] == 0 && i == 0) {
            zero_at_first_index(array,size);
            if (array[i] == 0) {
                for (int j = 0; j < size - 1; j++) {
                    array[j] = array[j + 1];
                }
                array[size - 1] = 0;
                break;
            }
        } else if (array[i] == 0 && i != 0) {
            zero_not_at_first_index(array,size,i);
            if (array[i] == 0) {
                array[i] = array[i + 1];
                array[i + 1] = array[i + 2];
                array[size - 1] = 0;
            }
        }
        else {
            continue;
        }
    }
}