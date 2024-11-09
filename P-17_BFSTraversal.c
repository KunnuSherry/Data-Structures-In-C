#include <stdio.h>
#include <stdlib.h>

struct queue{
    int r;
    int f;
    int size;
    int* arr;
};

int isEmpty(struct queue* head){
    if(head->f==head->r){
        printf("Queue Empty !\n");
        return 1;
    }
    return 0;
}

int isFull(struct queue* head){
    if(head->r==head->size-1){
        printf("Queue Full !\n");
        return 1;
    }
    return 0;
}

void enqueue(struct queue* head, int value){
    if(isFull(head)){
        printf("Element can't be Inserted!\n");
        return;
    }
    head->r = head->r+1;
    head->arr[head->r] = value;
}

int dequeue(struct queue* head){
    if(isEmpty(head)){
        printf("Element can't be deleted! \n");
        return -1;
    }
    head->f = head->f+1;
    return head->arr[head->f];
}

int main(){
    struct queue q;
    q.r = -1;
    q.f = -1;
    q.size = 400;
    q.arr = (int*)malloc(q.size*sizeof(int));

    //declaring a adjancy matrix
    int mar[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0}
    };
    
    int i = 0; //Starting traversal from 0
    int visited[7] = {0,0,0,0,0,0,0}; //visited array
    visited[i] = 1;
    printf("%d ", i);
    enqueue(&q, i);
    while(!isEmpty(&q)){
        int node = dequeue(&q);
        for(int j=0; j<7; j++){
            if (mar[node][j]==1 && visited[j]==0){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

}