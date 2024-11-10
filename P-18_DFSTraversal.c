#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int* arr;
};

int isEmpty(struct stack* s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}

int isFull(struct stack* s){
    if(s->top==s->size-1){
        return 1;
    }
    return 0;
}

void push(struct stack* s, int value){
    if(isFull(s)){
        printf("Stack Overflow!\n");
        return;
    }
    s->top++;
    s->arr[s->top] = value;
}

int pop(struct stack* s){
    if(isEmpty(s)){
        printf("Stack Underflow!\n");
        return -1;
    }
    int a = s->arr[s->top];
    s->top--;
    return a;
}

int main(){
    struct stack s;
    s.top = -1;
    s.size = 400;
    s.arr = (int*) malloc (s.size*sizeof(int));
    //declaring an adjancey matrix
    int mar[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0}
    };
    int value[7] = {0,0,0,0,0,0,0};
    int i;
    printf("Enter the starting Index: ");
    scanf("%d", &i);
    value[i] = 1;
    push(&s, i);
    while(!isEmpty(&s)){
        int popped = pop(&s);
        printf("%d ", popped);
        for(int j=0; j<7; j++){
            if(mar[popped][j]==1 && value[j]!=1){
                push(&s, j);
                value[j] = 1;
            }
        }
    }
}