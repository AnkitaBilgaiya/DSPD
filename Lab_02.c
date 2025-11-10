#include <stdio.h>
#define MAX 5
int stack[MAX], top = -1;

void push(int val) {
    if(top == MAX - 1)
        printf("Overflow\n");
    else
        stack[++top] = val;
}

void pop() {
    if(top == -1)
        printf("Underflow\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

void display() {
    if(top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack elements: ");
        for(int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}
void checkPalindrome() {
    if(top == -1) return;
    int i, flag = 1;
    for(i = 0; i <= top / 2; i++) {
        if(stack[i] != stack[top - i]) {
            flag = 0; break;
        }
    }
    if(flag) 
       printf("Palindrome\n");
    else 
       printf("Not Palindrome\n");
}

int main() {
    int choice, val;
    while(1) {
        printf("\n1.Push \n2.Pop\n 3.Display\n 4.Check Palindrome\n 5.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter value: "); 
                    scanf("%d", &val); 
                    push(val); 
                    break;
            case 2: pop(); 
                    break;
            case 3: display(); 
                    break;
            case 4: checkPalindrome(); 
                    break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
