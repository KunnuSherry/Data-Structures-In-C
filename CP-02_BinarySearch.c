#include <stdio.h>
#include <stdlib.h>

int binarysearch(int arr[], int target, int n){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==target){
            printf("Element is found at index %d", mid);
            return 0;
        }
        else if(arr[mid]>target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    printf("Element not found!");
    return 0;
    
}

int main() {
    int *arr;
    int n;
    int target;
    printf("Enter the number of elements you want in the array: ");
    scanf("%d", &n);
    
    arr = (int*)malloc(sizeof(int));
    for(int i=0; i<n; i++){
        printf("Enter the element at index %d ", i);
        scanf("%d", &arr[i]);
        printf("\n");
    }
    printf("Enter the number to be searched in the array: ");
    scanf("%d", &target);
    
    binarysearch(arr, target, n);
    
}