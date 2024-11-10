#include<stdio.h>

void swap(int a, int b, int arr[]){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void insertionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j>0; j--){
            if(arr[j] < arr[j-1]){
                swap(j, j-1, arr);  
            }
            else{
                break;  
            }
        }
    }
}

int main(){
    int arr[] = {4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]); 
    
    insertionSort(arr, n);
    
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}
