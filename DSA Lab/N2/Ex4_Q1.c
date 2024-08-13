#include <stdio.h>
#define MAX_SIZE 5

typedef struct List
{
    int data[MAX_SIZE];
    int size;
} List;

// Initialize List
void initList(List *list)
{
    list->size = 0;
}

// Add element to the end of the list
void add(List *list, int value)
{
    if (list->size < MAX_SIZE)
    {
        list->data[list->size] = value;
        list->size++;
    }
    else
    {
        printf("List is full. Cannot add more elements.\n");
    }
}

// Remove an element from the list at a specific index
void removeAt(List *list, int index)
{
    if (index == 0 || index < list->size)
    {
        for (int i = index; i < list->size - 1; i++)
        {
            list->data[i] = list->data[i + 1];
        }
        list->size--;
    }
    else
    {
        printf("Index out of range.\n");
    }
}

// Get an element from the list at a specific index
int get1(List *list, int index)
{
    if (index >= 0 && index < list->size)
    {
        return list->data[index];
    }
    else
    {
        printf("Index out of range.\n");
        return -1;
    }
}
// Print the elements of the list
void printList(List *list)
{
    if (list->size == 0)
    {
        printf("List is empty.\n");
        return;
    }
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

void insertele(List *list, int index, int value)
{
    if (index >= 0 && index <= list->size && list->size < MAX_SIZE)
    {
        for (int i = list->size; i > index; i--)
        {
            list->data[i] = list->data[i - 1];
        }
        list->data[index] = value;
        list->size++;
    }
    else
    {
        printf("Index out of range or list is full.\n");
    }
}

int search(List *list, int value){
    for(int i = 0; i < list->size;i++){
        if(list->data[i] == value){
            return i;
        }
    }
    return -1;
}

int main()
{
    List list;
    initList(&list);
    int choice, value, index;

    while (1)
    {  
        printf("\n-------------List Operations-------------\n");
        printf("1. Add element to the list\n");
        printf("2. Remove element from index of the list\n");
        printf("3. Get element from the list\n");
        printf("4. Print the list\n");
        printf("5. Insert element at a specific index\n");
        printf("6. Search for an element\n");
        printf("7. Exit\n");
        printf("-------------Enter your choice-------------\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value of add: ");
            scanf("%d", &value);
            add(&list, value);
            break;

        case 2:
            printf("Enter the index: ");
            scanf("%d", &index);
            removeAt(&list, index);
            break;

        case 3:
            printf("Enter the index to get element: ");
            scanf("%d", &index);
            value = get1(&list, index);
            if (value != -1)
            {
                printf("Element at index %d is %d\n", index, value);
            }
            break;

        case 4:
            printList(&list);
            break;
        case 5:
            printf("Enter the index to insert at: ");
            scanf("%d", &index);
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insertele(&list, index, value);
            break;
        case 6:
            printf("Enter the value to search: ");
            scanf("%d", &value);
            index = search(&list, value);
            if (index != -1){
                printf("Element %d is found %d.", value ,index);
            }
            else{
                printf("Element %d is not found", value);
            }
            break;
            
        case 7:
            printf("Exiting....");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}