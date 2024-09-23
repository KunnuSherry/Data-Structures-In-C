#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char* arr;
};

int isEmpty(struct stack* ptr)
{
    if(ptr->top==-1){
        return 1;
    }
    return 0;
}

int isFull(struct stack* ptr)
{
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack* ptr, char exp){
    if(isFull(ptr)){
        printf("Stack Overflow!\n");
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = exp;
}

void pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow!\n");
        return;
    }
    ptr->top--;
}

int parenthesisMatch(char * exp)
{
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char*)malloc(s->size*sizeof(struct stack));
    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i]=='('){
            push(s, '(');
        }
        else if(exp[i]==')'){
            if(isEmpty(s)){
                return 0;
            }
            pop(s);
        }
    }
    if(isEmpty(s)){
        return 1;
    }
    return 0;
}

int main() {
    char * exp = "8*(9)))";
    
    if(parenthesisMatch(exp)){
        printf("Parenthesis Matched!");
    }
    else{
        printf("Parenthesis not Matched!");
    }
    return 0;
}