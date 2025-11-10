#include <stdio.h>
#define SIZE 7

int main() {
    int hash[SIZE], keys[20], n, i, index;
    for(i = 0; i < SIZE; i++)
        hash[i] = -1;
    printf("Enter number of keys: ");
    scanf("%d", &n);
    printf("Enter keys: ");
    for(i = 0; i < n; i++)
        scanf("%d", &keys[i]);

    for(i = 0; i < n; i++) {
        index = keys[i] % SIZE;
        while(hash[index] != -1)
            index = (index + 1) % SIZE;
        hash[index] = keys[i];
    }

    printf("\nFinal Hash Table:\n");
    for(i = 0; i < SIZE; i++)
        printf("Slot %d -> %d\n", i, hash[i]);
    return 0;
}