#include <stdio.h>
int main() {
    int n, i, arr[100], sum_even = 0, sum_odd = 0;
    printf("Enter number of elements (max 100): ");
    scanf("%d", &n);

    if(n < 1 || n > 100) {
        printf("Error: number of elements must be between 1 and 100.\n");
        return 1;  
    }

    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n; i++) {
        if(i % 2 == 0)
            sum_even += arr[i];
        else
            sum_odd += arr[i];
    }

    printf("Sum of even positions: %d\n", sum_even);
    printf("Sum of odd positions: %d\n", sum_odd);
    return 0;
}
