#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* create() {
    int val;
    printf("Enter data for Node (0 to stop): ");
    scanf("%d", &val);

    if (val == 0) {
        return NULL;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;

    printf("Enter data for Left Child of %d:\n", val);
    newnode->left = create();

    printf("Enter data for Right Child of %d:\n", val);
    newnode->right = create();

    return newnode;
}

void Inorder(struct node *root) {
    if (root != NULL) {
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

void Preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

int main() {
    struct node *root = NULL;

    printf("Create Binary Tree:\n");
    root = create();

    printf("\nInorder Traversal: ");
    Inorder(root);

    printf("\nPreorder Traversal: ");
    Preorder(root);

    return 0;
}
