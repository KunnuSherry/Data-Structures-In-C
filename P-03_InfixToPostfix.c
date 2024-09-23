#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow!\n");
    }
    char x = ptr->arr[ptr->top];
    ptr->top--;
    return x;
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1;
    else
        return 0;
}

int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}

char* infixToPostfix(char* infix){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (char*)malloc(s->size*sizeof(char));
    char* postfix = (char*)malloc((strlen(infix)+1)*sizeof(char));
    int i=0; //to traverse the infix
    int j=0; //to traverse the postfix
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])>precedence(s->arr[s->top])){
                push(s, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while(!isEmpty(s)){
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {
    char* infix = "a+b*c/d-e";
    printf("Infix is: %s\n", infix);
    char* postfix = infixToPostfix(infix);
    printf("Postfix is: %s", postfix);
    return 0;
}