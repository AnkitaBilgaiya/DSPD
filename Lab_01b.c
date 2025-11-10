#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    if(arr == NULL || n == 0) return -1;
    int start = 0, end = n - 1, mid;
    while(start <= end) {
        mid = (start + end) / 2;
        printf("Mid index: %d, Value: %d\n", mid, arr[mid]);
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main() {
    int n, key, arr[100], i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter sorted array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    int result = binarySearch(arr, n, key);
    if(result == -1)
        printf("NULL\n");
    else
        printf("Found at index %d\n", result);
    return 0;
}

