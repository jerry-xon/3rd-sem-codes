#include <stdio.h>

int LinearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int arr[10] = {12, 83, 91, 43, 45, 69, 89, 37, 1, 14};
    int size = sizeof(arr) / sizeof(arr[0]); 
    int key;

    printf("Enter the key: ");
    scanf("%d", &key);

    int result = LinearSearch(arr, size, key); 

    if (result != -1) {
        printf("Element found at index: %d\n", result); 
    } else {
        printf("Element not found\n"); 
    }

    return 0;
}