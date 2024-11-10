#include<stdio.h>

void maxHeapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l]>arr[largest]){
        largest = l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest = r;
    }
    if(largest!=i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        maxHeapify(arr, i, 0);
    }
}


int main(){
    int arr[] = {15,5,20,1,17,10,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, n);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}