#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}; 
typedef struct Node node;

node *CreatingRoot(int number) {
    node *root = (node*)malloc(sizeof(node));
    root->data = number;
    root->left = NULL;
    root->right = NULL;
    return root;
}

node *addingItems(node *root, int addNum) {
    if (root == NULL)
        return CreatingRoot(addNum);
    else {
        if (addNum < root->data)
            root->left = addingItems(root->left, addNum);
        else
            root->right = addingItems(root->right, addNum);
    }
    return root;
}

void preOrder(node *root){
    if (root != NULL){
        printf("%d", root -> data);
        preOrder(root -> left);
        preOrder(root -> right);
    }
}

void inOrder(node *root){
    if (root != NULL){
        inOrder(root -> left);
        printf("%d", root -> data);
        inOrder(root -> right);
    }
}

void postOrder(node *root){
    if (root != NULL){
        postOrder(root -> left);
        postOrder(root -> right);
        printf("%d", root -> data);
    }
}

int main() {
    node *root = NULL; // Initialize the root to NULL
    int num, i = 0;

    while (i < 7) {
        printf("Please enter a number: ");
        scanf("%d", &num);
        root = addingItems(root, num);
        i++;
    }

    printf("\nPreOrder: ");
    preOrder(root);
    printf("\nInOrder: ");
    inOrder(root);
    printf("\nPostOrder: \n");
    postOrder(root);

    return 0;
}
