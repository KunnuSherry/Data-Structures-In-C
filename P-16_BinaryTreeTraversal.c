//Performing traversals in binary tree 1. in-order 2. postorder 3. preorder
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

//Inorder traversal
void inorder(struct node* root){
    if (root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}
void preorder(struct node* root){
    if (root==NULL){
        return;
    }
    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root){
    if (root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->value);
}

int main(){
    struct node* root;
    root=create();
    printf("Inorder Traversal:\n");
    inorder(root);
    printf("\n");
    printf("Preorder Traversal:\n");
    preorder(root);
    printf("\n");
    printf("Postorder Traversal:\n");
    postorder(root);
    printf("\n");
}