#include <stdio.h>

void swap(int a, int b, int arr[]){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int ele = arr[i];
        for(int j=i+1; j<n; j++){
            if(ele>arr[j]){
                swap(j, i, arr);
            }
        }
    }
}

int main(){
    int arr[] = {4,3,2,1};
    int n;
    n=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted Array: \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}