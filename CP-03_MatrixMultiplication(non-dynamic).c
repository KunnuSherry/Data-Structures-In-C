//Program to perform binary multiplication non-dynamically
#include <stdio.h>

int main(){
    int mat1[2][2];
    int mat2[2][2];
    int res[2][2] = {{0,0},{0,0}};
    
    printf("For Matrix I: \n");
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("Write the element at %d, %d : ", i, j);
            scanf("%d", &mat1[i][j]);
            printf("\n");
        }
    }
    printf("For Matrix II: \n");
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("Write the element at %d, %d : ", i, j);
            scanf("%d", &mat2[i][j]);
            printf("\n");
        }
    }
    
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                res[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }
    printf("Result Matrix: \n");
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}