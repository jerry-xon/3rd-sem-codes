#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void print_data(struct node *head){
  if(head == NULL){
    printf("List is empty.\n");
  }
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
    head->link = current; //this line is to connect both nodes head and current

    current = (struct node *)malloc(sizeof(struct node));
    current->data = 30;
    current->link = NULL;
    head->link->link = current; 

    current = (struct node *)malloc(sizeof(struct node));
    current->data = 40;
    current->link = NULL;
    head->link->link->link = current;    

    print_data(head);
  return 0;
}