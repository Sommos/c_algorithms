#include <stdio.h>
#include <stdlib.h>

#define MIN_MERGE 32

void merge(int arr[], int left, int mid, int right) {
    int left_size = mid - left + 1;
    int right_size = right - mid;

    int left_arr[left_size];
    int right_arr[right_size];

    for(int i = 0; i < left_size; i++) {
        left_arr[i] = arr[left + i];
    }
    for(int j = 0; j < right_size; j++) {
        right_arr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while(i < left_size && j < right_size) {
        if(left_arr[i] <= right_arr[j]) {
            arr[k++] = left_arr[i++];
        } else {
            arr[k++] = right_arr[j++];
        }
    }

    while(i < left_size) {
        arr[k++] = left_arr[i++];
    }
    while(j < right_size) {
        arr[k++] = right_arr[j++];
    }
}

void insertion_sort(int arr[], int left, int right) {
    for(int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void tim_sort(int arr[], int size) {
    for(int i = 0; i < size; i += MIN_MERGE) {
        insertion_sort(arr, i, i + MIN_MERGE - 1);
    }
    for(int size = MIN_MERGE; size < size; size *= 2) {
        for(int left = 0; left < size; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < size)
                        ? left + 2 * size - 1
                        : size - 1;
            merge(arr, left, mid, right);
        }
    }
}