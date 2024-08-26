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

struct node *addbeg(struct node* head, int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = head;
    if (head != NULL) {  // Ensure head is not NULL before accessing head->prev
        head->prev = temp;
    }
    head = temp;
    return head;
}

int main() {
    struct node* head = NULL;
    struct node* ptr;

    head = addempty(head, 50);
    head = addbeg(head, 20);

    ptr = head;
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
