#include <stdio.h>
void swap(int a, int b, int arr[]){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void shellSort(int arr[], int n){
    for(int gap=n/2; gap>=1; gap/=2){
        for(int j=gap; j<n; j++){
            for(int i=j-gap; i>=0; i-=gap){
                if(arr[i]<arr[i+gap]){
                    break;
                }
                else{
                    swap(i, i+gap, arr);
                }
            }
        }
    }
}

int main() {
    int arr[] = {23,1,45,2,4,2,22,67,12};
    int n = sizeof(arr)/4;
    shellSort(arr,n);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}