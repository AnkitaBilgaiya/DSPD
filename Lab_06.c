#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct node* insert(struct node* root, int data) {
    if(root == NULL) 
       return createNode(data);
    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
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

struct node* deleteLeaf(struct node* root, int key) {
    if(root == NULL) return NULL;
    if(root->data == key && root->left == NULL && root->right == NULL) {
        free(root); 
        return NULL;
    }
    root->left = deleteLeaf(root->left, key);
    root->right = deleteLeaf(root->right, key);
    return root;
}
int main() {
    struct node* root = NULL;
    int ch, val;
    while(1) {
        printf("\n1.Search\n 2.Insert\n 3.Delete Leaf\n 4.Exit\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Enter value to search: "); 
                    scanf("%d", &val); 
                    search(root, val); 
                    break;
            case 2: printf("Enter value to insert: "); 
                    scanf("%d", &val); 
                    root = insert(root, val); 
                    break;
            case 3: printf("Enter leaf value to delete: "); 
                    scanf("%d", &val); 
                    root = deleteLeaf(root, val); 
                    break;
            case 4: return 0;
        }
    }
}
