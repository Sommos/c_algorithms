#include "tim_sort.c"
#include "block_sort.c"

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 91};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    tim_sort(arr, size);

    printf("(Tim Sort) Sorted array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    block_sort(arr, size);

    printf("(Block Sort) Sorted array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}