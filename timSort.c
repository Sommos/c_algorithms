#include <stdio.h>
#include <stdlib.h>

#define MIN_MERGE 32

void merge(int arr[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int leftArr[leftSize];
    int rightArr[rightSize];

    for(int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }
    for(int j = 0; j < rightSize; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while(i < leftSize && j < rightSize) {
        if(leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while(i < leftSize) {
        arr[k++] = leftArr[i++];
    }
    while(j < rightSize) {
        arr[k++] = rightArr[j++];
    }
}

void insertionSort(int arr[], int left, int right) {
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

void timSort(int arr[], int size) {
    for(int i = 0; i < size; i += MIN_MERGE) {
        insertionSort(arr, i, i + MIN_MERGE - 1);
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