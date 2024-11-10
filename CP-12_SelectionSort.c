#include <stdio.h>

void selectionSort(int arr[], int n) {
    int minIndex;
    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int arr[] = {4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    printf("Array After Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
