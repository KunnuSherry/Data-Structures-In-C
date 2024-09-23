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
    return ptr->top == -1;
}

int isFull(struct stack* ptr)
{
    return ptr->top == ptr->size - 1;
}

void push(struct stack* ptr, char exp)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow!\n");
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = exp;
}

char pop(struct stack* ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!\n");
        return '\0'; // Return null character if underflow occurs
    }
    char x = ptr->arr[ptr->top];
    ptr->top--;
    return x;
}

int match(char a, char b)
{
    if (a == '(' && b == ')')
        return 1;
    if (a == '{' && b == '}')
        return 1;
    if (a == '[' && b == ']')
        return 1;
    return 0;
}

int parenthesisMatch(char *exp)
{
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char*)malloc(s->size * sizeof(char));
    
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            char popped_char = pop(s);
            if (!match(popped_char, exp[i]))
            {
                return 0;
            }
        }
    }
    
    if (isEmpty(s))
    {
        return 1;
    }
    return 0;
}

int main()
{
    char* exp = "{desd}+[8*(9)]";
    
    if (parenthesisMatch(exp))
    {
        printf("Parentheses Matched!");
    }
    else
    {
        printf("Parentheses not Matched!");
    }
    return 0;
}
