#include <stdio.h>
#define MAX 5
char queue[MAX];
int front = -1, rear = -1;

void insert(char val) {
    if(rear == MAX - 1)
        printf("Overflow\n");
    else {
        if(front == -1) front = 0;
        queue[++rear] = val;
    }
}

void delete() {
    if(front == -1 || front > rear)
        printf("Underflow\n");
    else
        printf("Deleted: %c\n", queue[front++]);
}

void display() {
    if(front == -1 || front > rear)
        printf("Queue empty\n");
    else {
        printf("Queue: ");
        for(int i = front; i <= rear; i++)
            printf("%c ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice;
    char val;
    while(1) {
        printf("\n1.Insert \n 2.Delete \n 3.Display \n 4.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter char: "); 
                    scanf(" %c", &val); 
                    insert(val);
                    break;
            case 2: delete(); 
                    break;
            case 3: display(); 
                    break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
