#include<stdio.h>
#include<stdlib.h>
void main(){
int rows, columns;
int zero =  0;
int n_zero = 0;


printf("Enter the number of rows: ");
scanf("%d \n", &rows);
printf("Enter the number of columns: ");
scanf("%d \n", &columns);
int* arr = (int*)malloc(rows*columns*sizeof(int));

printf("Enter the respective elements: \n");
for(int i=0; i<rows; i++){
    for(int j=0; j<columns; j++){
        printf("Write the element(%d,%d): ", i,j);
        scanf("%d", &arr[i*rows+j]);
    }
}

for(int i=0; i<rows; i++){
    for(int j=0; j<columns; j++){
        if(arr[i*rows+j]==0){
            zero++;
        }
        else{
            n_zero++;
        }
    }
}

if(zero/n_zero>0.5){
    printf("Yes, it's an Sparse Matrix");
}
else{
    printf("No, It' not");
}
}