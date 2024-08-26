#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *addempty(struct node *head, int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;  // Correctly assign the new node to head
    return head;
}

struct node *add_end(struct node *head, int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = NULL;
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}
struct node* add_at_pos(struct node* head, int data, int position){
    struct node *newp = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;
    newp = addempty(newp, data);
    
    while(position != 2){
        temp = temp->next;
        position--;
    }
    if(temp->next == NULL){
        temp->next = newp;
        newp->prev = temp;
    }else{
    temp2 = temp->next;
    temp->next = newp;
    temp2->prev = newp;
    newp->next = temp2;
    newp->prev = temp;
    }
    
    return head;
}


int main() {
    struct node* head = NULL;
    struct node* ptr;
    int position = 2;
    head = addempty(head, 50);
    head = add_end(head, 60);
    head = add_end(head, 30);
    head = add_end(head, 70);
    head = add_at_pos(head,45,position);


    ptr = head;
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
