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
    head = temp; 
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

struct node *addbeg(struct node* head, int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = head;
    if (head != NULL) {  
        head->prev = temp;
    }
    head = temp;
    return head;
}

struct node* add_at_pos(struct node* head, int data, int position){
    struct node *newp = malloc(sizeof(struct node));
    newp->data = data;
    newp->next = NULL;
    newp->prev = NULL;

    struct node *temp = head;

    while (position > 2 && temp->next != NULL) {
        temp = temp->next;
        position--;
    }

    if (temp->next == NULL) {
        temp->next = newp;
        newp->prev = temp;
    } else {
        struct node *temp2 = temp->next;
        temp->next = newp;
        newp->prev = temp;
        newp->next = temp2;
        temp2->prev = newp;
    }
    
    return head;
}

struct node* CreateDLL(struct node* head) {
    int n, data, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n == 0) {
        return head;
    }

    printf("Enter element 1 of the List: ");
    scanf("%d", &data);
    head = addempty(head, data);

    for (i = 1; i < n; i++) {
        printf("Enter element %d of the list: ", i + 1);
        scanf("%d", &data);
        head = add_end(head, data);
    }

    return head;
}

struct node* del_beg(struct node* head) {
    if (head == NULL) {
        return NULL;
    }
    
    struct node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
    return head;
}

int sumnodes(struct node* head){
    int sum = 0;
    struct node* temp = head;
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

struct node* del_end(struct node* head) {
    if (head == NULL) {
        return NULL;
    }

    struct node* temp = head;

    if (temp->next == NULL) {
        free(temp);
        return NULL;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);

    return head;
}

int main() {
    struct node* head = NULL;
    struct node* ptr;
    int data, position;

    head = CreateDLL(head);

    printf("Enter element to add at the beginning: ");
    scanf("%d", &data);
    head = addbeg(head, data);

    printf("Enter position to add at: ");
    scanf("%d", &position);
    printf("Enter data to be added: ");
    scanf("%d", &data);
    head = add_at_pos(head, data, position);

    ptr = head;
    printf("Before deletion:\n");
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }

    printf("After end node deletion:\n");
    head = del_end(head);
    ptr = head; 
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }

    printf("After first node deletion:\n");
    head = del_beg(head); 
    ptr = head;  
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }

    int sum;
    sum = sumnodes(head); 
    printf("Sum of nodes: %d\n", sum);

    return 0;
}
