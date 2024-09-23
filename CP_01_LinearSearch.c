#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int* arr = (int*)malloc(size*sizeof(int));
    printf("Enter the element of array: \n");
    for(int i=0; i<size; i++){
        printf("Enter the element %d : ",i+1);
        scanf("%d\n", &arr[i]);
    }
    int ele;
    printf("Enter the element to be found: ");
    scanf("%d", &ele);
    for(int i=0; i<size; i++){
        if(arr[i]==ele){
            printf("Element found at %d index: ", i);
        }
        else{
            printf("Element not found :)");
        }
    }
    return 0;

}