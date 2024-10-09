#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

//main function
int main()
{   struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;
    printf("%d",head->data);
    
  return 0;
}