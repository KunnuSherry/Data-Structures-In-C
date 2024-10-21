//Performing insertion in binary tree

#include <stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* left;
    struct node* right;
};

struct node* create(){
    int x;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &x);
    if(x==-1){
        return NULL;
    }
    newnode->value = x;
    printf("For the left child of %d\n", x);
    newnode->left = create();
    printf("For the right child of %d\n", x);
    newnode->right = create();
    return newnode;
    
}

int main(){
    struct node* root;
    root=create();
}