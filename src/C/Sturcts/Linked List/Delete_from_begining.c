#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node* del_beg(struct node *head){
    if(head == NULL)
        printf("List is already empty.\n");
    else{
        struct node *temp = head;
        head = head->link;
        free(temp);
        temp = NULL;
    }
    return head;
}

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

    struct node *ptr = NULL;
    add_at_end(head,50);
    add_at_end(head,30);
    add_at_end(head,69);

    head = del_beg(head);
    ptr = head;

  
    print_data(head);

  return 0;
}