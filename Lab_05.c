#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* create(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct node* insert(struct node* root, int data) {
    if(root == NULL) return create(data);
    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void inorder(struct node* root) {
    if(root) { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); }
}
void preorder(struct node* root) {
    if(root) { 
        printf("%d ", root->data); 
        preorder(root->left); 
        preorder(root->right); }
}
void postorder(struct node* root) {
    if(root) { 
        postorder(root->left); 
        postorder(root->right); 
        printf("%d ", root->data); }
}

void search(struct node* root, int key) {
    if(root == NULL) { 
        printf("NULL\n"); 
        return; }
    if(root->data == key) 
        printf("Found\n");
    else if(key < root->data) 
        search(root->left, key);
    else 
         search(root->right, key);
}

int main() {
    struct node* root = NULL;
    int n, data, key;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("Inorder: "); 
    inorder(root);
    printf("\nPreorder: "); 
    preorder(root);
    printf("\nPostorder: "); 
    postorder(root);
    printf("\nEnter element to search: "); 
    scanf("%d", &key);
    search(root, key);
    return 0;
}


