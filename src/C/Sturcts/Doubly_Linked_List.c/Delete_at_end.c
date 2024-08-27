#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *addempty(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp; // Correctly assign the new node to head
    return head;
}

struct node *add_end(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = NULL;
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}

struct node *CreateDLL(struct node *head)
{
    int n, data, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n == 0)
    {
        return head;
    }
    printf("Enter element 1 of the List: ");
    scanf("%d", &data);
    head = addempty(head, data);

    for (i = 1; i < n; i++)
    {
        printf("Enter element %d of the list: ", i + 1);
        scanf("%d", &data);
        head = add_end(head, data);
    }
    return head;
}
struct node *del_end(struct node *head)
{
    struct node *temp = NULL;
    struct node *temp2 = NULL;
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp2 = temp->prev;
    temp2->next = NULL;
    free(temp);
    return head;
}

void print_data(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node *head = NULL;
    head = CreateDLL(head);
    printf("Before Deletion\n");
    print_data(head);

    printf("After Deletion\n");
    head = del_end(head);
    print_data(head);

    return 0;
}
