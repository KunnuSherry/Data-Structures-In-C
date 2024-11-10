#include <stdio.h>
#include <stdlib.h>

#define MAX 10  


struct TwoStacks {
    int arr[MAX];  
    int top1;      
    int top2;      
};

void pushStack1(struct TwoStacks* stacks, int value) {
    if (stacks->top1 < stacks->top2 - 1) {
        stacks->arr[++(stacks->top1)] = value;
        printf("Pushed %d to Stack 1\n", value);
    } else {
        printf("Overflow: Stack 1 is full\n");
    }
}

void pushStack2(struct TwoStacks* stacks, int value) {
    if (stacks->top1 < stacks->top2 - 1) {
        stacks->arr[--(stacks->top2)] = value;
        printf("Pushed %d to Stack 2\n", value);
    } else {
        printf("Overflow: Stack 2 is full\n");
    }
}

int popStack1(struct TwoStacks* stacks) {
    if (stacks->top1 == -1) {
        printf("Underflow: Stack 1 is empty\n");
        return -1; 
    } else {
        return stacks->arr[(stacks->top1)--]; 
    }
}

int popStack2(struct TwoStacks* stacks) {
    if (stacks->top2 == MAX) {
        printf("Underflow: Stack 2 is empty\n");
        return -1; 
    } else {
        return stacks->arr[(stacks->top2)++];
    }
}

void printStack1(struct TwoStacks* stacks) {
    if (stacks->top1 == -1) {
        printf("Stack 1 is empty\n");
    } else {
        printf("Stack 1: ");
        for (int i = 0; i <= stacks->top1; i++) {
            printf("%d ", stacks->arr[i]);
        }
        printf("\n");
    }
}

void printStack2(struct TwoStacks* stacks) {
    if (stacks->top2 == MAX) {
        printf("Stack 2 is empty\n");
    } else {
        printf("Stack 2: ");
        for (int i = MAX - 1; i >= stacks->top2; i--) {
            printf("%d ", stacks->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct TwoStacks stacks;

    stacks.top1 = -1;  
    stacks.top2 = MAX; 

    pushStack1(&stacks, 10);
    pushStack1(&stacks, 20);
    pushStack2(&stacks, 30);
    pushStack2(&stacks, 40);

    printStack1(&stacks);
    printStack2(&stacks);

    printf("Popped from Stack 1: %d\n", popStack1(&stacks));
    printf("Popped from Stack 2: %d\n", popStack2(&stacks));

    printStack1(&stacks);
    printStack2(&stacks);

    return 0;
}
