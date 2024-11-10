#include <stdio.h>

void swap(int a, int b, int arr[]){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int arr[], int lb, int ub){
    int pivot  = arr[lb];
    int start  = lb;
    int end = ub;
    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            swap(start, end, arr);
        }
    }
    swap(lb, end, arr);
    return end;
}

void quickSort(int arr[], int lb, int ub){
    if(lb<ub){
        int loc = partition(arr, lb, ub);
        quickSort(arr, lb, loc-1);
        quickSort(arr, loc+1, ub);

    }
}

int main(){
    int arr[] = {4,3,2,1};
    quickSort(arr, 0, 3);
    printf("Sorted Array: \n");
    for(int i=0; i<4; i++){
        printf("%d ", arr[i]);
    }
}