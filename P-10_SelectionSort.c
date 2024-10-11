#include <stdio.h>
int main(){
    int arr[] = {7,4,10,8,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        if (min!=i){
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    for(int k=0; k<n; k++){
        printf("%d ", arr[k]);
    }
}