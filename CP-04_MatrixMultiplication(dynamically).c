#include <stdio.h>
#include <stdlib.h>

int main(){
    int r1;
    int c1;
    int r2;
    int c2;
    printf("Enter Rows and Columns of Matrix 1: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter Rows and Columns of Matrix 2: ");
    scanf("%d %d", &r2, &c2);
    int* mat1 = (int*)malloc(r1*c1*sizeof(int));
    int* mat2 = (int*)malloc(r1*c1*sizeof(int));
    printf("For Matrix 1: \n");
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            printf("Enter the element at %d, %d: ", i, j);
            scanf("%d", &mat1[i*c1+j]);
            printf("\n");
        }
    }
    printf("For Matrix 2: \n");
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            printf("Enter the element at %d, %d: ", i, j);
            scanf("%d", &mat2[i*c2+j]);
            printf("\n");
        }
    }
    if(c1==r2){
        int* res = (int*)malloc(r1*c2*sizeof(int));
        for(int i=0; i<r1; i++){
            for(int j=0; j<c2; j++){
                res[i*c2+j]=0;
                for(int k=0; k<r1*c2; k++){
                    res[i*c2+j]+=mat1[i*c2+k]*mat2[k*c2+j];
                }
            }
        }
        printf("Resultant Matrix: \n");
        for(int i=0; i<r1; i++){
            for(int j=0; j<c2; j++){
                printf("%d ", res[i*c2+j]);
            }
            printf("\n");
        }
    }
    else{
        printf("Operation can't be done!");
    }
    
}