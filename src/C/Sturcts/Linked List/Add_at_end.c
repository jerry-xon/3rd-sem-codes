#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void add_at_end(struct node *head, int data){
    struct node *ptr ,*temp;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
}
void print_data(struct node *head){
  if(head == NULL)
    printf("List is empty.\n");
  struct node *ptr = NULL;
  ptr = head;
  while(ptr != NULL){
    printf("%d\n",ptr->data);
    ptr = ptr->link;
}}

int main()
{   struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;
    
    struct node *current = NULL;
    current = (struct node *)malloc(sizeof(struct node));
    current->data = 20;
    current->link = NULL;
    head->link = current;

    current = (struct node *)malloc(sizeof(struct node));
    current->data = 30;
    current->link = NULL;
    head->link->link = current; 

    current = (struct node *)malloc(sizeof(struct node));
    current->data = 40;
    current->link = NULL;
    head->link->link->link = current;    

    add_at_end(head,50);
    print_data(head);

  return 0;
}