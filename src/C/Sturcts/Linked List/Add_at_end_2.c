#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *add_at_end(struct node *ptr, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
    return temp;
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

    struct node *ptr = head;
    ptr = add_at_end(ptr, 20);
    ptr = add_at_end(ptr, 30);
    ptr = add_at_end(ptr, 40);

    ptr = head;

    print_data(head);

    return 0;
}