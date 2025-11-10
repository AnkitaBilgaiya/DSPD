#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp, *newnode;
    int num, count = 0;
    printf("Enter elements (0 to stop):\n");
    while(1) {
        scanf("%d", &num);
        if(num == 0) break;
        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = num;
        newnode->next = NULL;
        if(head == NULL)
            head = temp = newnode;
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    printf("Linked List: ");
    temp = head;
    while(temp != NULL) {
        printf("%d => ", temp->data);
        count++;
        temp = temp->next;
    }
    printf("NULL\nTotal Nodes: %d\n", count);
    return 0;
}
