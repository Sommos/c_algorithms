#include <stdio.h>
#include <stdlib.h>

#include "tim_sort.c"

#define BLOCK_SIZE 4

void block_sort(int arr[], int size) {
    int num_blocks = size / BLOCK_SIZE + (size % BLOCK_SIZE != 0);

    for(int i = 0; i < num_blocks; i++) {
        int left = i * BLOCK_SIZE;
        int right = (i + 1) * BLOCK_SIZE - 1;
        if(right >= size) {
            right = size - 1;
        }
        insertion_sort(arr + left, right - left + 1);
    }

    int output_index = 0;
    int block_indices[num_blocks];
    for(int i = 0; i< num_blocks; i++) {
        block_indices[i] = i * BLOCK_SIZE;
    }

    while(output_index < size) {
        int min_index = -1;
        int min_value = INT_MAX;

        for(int i = 0; i < num_blocks; i++) {
            if(block_indices[i] < (i + 1) * BLOCK_SIZE && arr[block_indices[i]] < min_value) {
                min_value = arr[block_indices[i]];
                min_index = i;
            }
        }

        if(min_index == -1) {
            break;
        }

        arr[output_index++] = min_value;
        block_indices[min_index]++;
    }
}