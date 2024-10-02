#include<stdio.h>
#include<stdlib.h>
void main(){
int rows, columns;
int zero =  0;
int n_zero = 0;


printf("Enter the number of rows: ");
scanf("%d", &rows);
printf("Enter the number of columns: ");
scanf("%d", &columns);
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

printf("Performing Array Representation: \n");
int sparse[n_zero][3], k=0;
for(int i=0; i<rows; i++){
    for(int j=0; j<columns; j++){
        if(arr[i*rows+j]!=0){
            sparse[k][0] = i;
            sparse[k][1] = j;
            sparse[k][2] = arr[i*rows+j];
            k++;
        }
    }
}

printf("This is the Matrix of representation: \n");
for(int i=0; i<n_zero; i++){
    for(int j=0; j<3; j++){
        printf("%d ", sparse[i][j]);
    }
    printf("\n");
}
}