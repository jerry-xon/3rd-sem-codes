#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};
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

struct node *addempty(struct node *head, int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;  // Correctly assign the new node to head
    return head;
}

int main() {
    struct node* head = NULL;
    struct node* ptr;

    head = addempty(head, 50);
    head = add_end(head,20);

    ptr = head;
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
