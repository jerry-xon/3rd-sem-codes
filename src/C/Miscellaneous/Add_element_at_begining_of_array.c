// this code is about adding a element at the begining of an array.
// the time complexity of this will be O(n).
#include <stdio.h>

int add_beg(int arr[], int size, int data)
{
    for (int i = size - 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = data; 
    return size + 1;
}


int main()
{
    int arr[10];
    int n;
    int data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elementes:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
     printf("Enter the element to be added at the beginning: ");
    scanf("%d", &data);
    
    int new_size = add_beg(arr, n, data);

    printf("Array after insertion: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}