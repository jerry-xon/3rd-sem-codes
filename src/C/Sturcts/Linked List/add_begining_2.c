#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void add_beg(struct node **head, int data)
{
    struct node *ptr;

    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = NULL;

    ptr->link = *head;
    *head = ptr;
}
void print_data(struct node *head)
{
    if (head == NULL)
        printf("List is empty.\n");
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}

int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    struct node *ptr = NULL;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = 20;
    ptr->link = NULL;
    head->link = ptr;

    int data = 3;

    add_beg(&head, data);
    ptr = head;

    print_data(head);

    return 0;
}
