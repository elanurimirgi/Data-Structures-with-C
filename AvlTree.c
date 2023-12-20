#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a > b) ? a : b)

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

typedef struct Node node;

int height(node *hght) {
    if (hght == NULL)
        return 0;
    else
        return hght->height;
}

node *rotationRight(node *x) {
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return y;
}

node *rotationLeft(node *x) {
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return y;
}

int balanceFactor(node *node) {
    if (node == NULL)
        return 0;
    else
        return height(node->left) - height(node->right);
}

node *createNode(int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

node *insertion(node *root, int data) {
    if (root == NULL)
        return createNode(data);
    else {
        if (data < root->data)
            root->left = insertion(root->left, data);
        else
            root->right = insertion(root->right, data);
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = balanceFactor(root);

    if (balance > 1) {
        if (data < root->left->data)
            return rotationRight(root);
        else {
            root->left = rotationLeft(root->left);
            return rotationRight(root);
        }
    }

    if (balance < -1) {
        if (data > root->right->data)
            return rotationLeft(root);
        else {
            root->right = rotationRight(root->right);
            return rotationLeft(root);
        }
    }

    return root;
}

int countNodes(node *root) {
    if (root == NULL)
        return 0;
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    node *root = NULL;
    int num, i = 0;

    while (i < 7) {
        printf("Please enter a number: ");
        scanf("%d", &num);
        root = insertion(root, num);
        i++;
        printf("Number of nodes: %d\n", countNodes(root));
    }
    return 0;
}
