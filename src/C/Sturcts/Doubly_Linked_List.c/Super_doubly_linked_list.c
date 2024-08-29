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

struct node *add_end(struct node *head, int data) {
    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr = head;
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) {
        return temp;
    }
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}

struct node *add_pos(struct node *head, int data, int pos) {
    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr = head;
    temp->data = data;
    if (pos == 1) {
        temp->prev = NULL;
        temp->next = head;
        if (head != NULL) {
            head->prev = temp;
        }
        head = temp;
    } else {
        for (int i = 1; i < pos - 1 && ptr != NULL; i++) {
            ptr = ptr->next;
        }
        if (ptr != NULL) {
            temp->next = ptr->next;
            temp->prev = ptr;
            if (ptr->next != NULL) {
                ptr->next->prev = temp;
            }
            ptr->next = temp;
        } else {
            printf("Position out of bounds.\n");
            free(temp);
        }
    }
    return head;
}

struct node *del_beg(struct node *head) {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

struct node *del_end(struct node *head) {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
    return head;
}

struct node *del_pos(struct node *head, int pos) {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }
    if (pos == 1) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp != NULL) {
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
    } else {
        printf("Position out of bounds.\n");
    }
    return head;
}

int search_by_element(struct node *head, int data) {
    struct node *ptr = head;
    int pos = 1;
    while (ptr != NULL) {
        if (ptr->data == data) {
            return pos;
        }
        ptr = ptr->next;
        pos++;
    }
    return -1; // Element not found
}

int search_by_position(struct node *head, int pos) {
    struct node *ptr = head;
    int current_pos = 1;
    while (ptr != NULL) {
        if (current_pos == pos) {
            return ptr->data;
        }
        ptr = ptr->next;
        current_pos++;
    }
    return -1; // Position out of bounds
}

void print_data(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d <- -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int choice, data, pos;

    do {
        printf("\nDoubly Linked List Menu\n");
        printf("1. Add at Beginning\n");
        printf("2. Add at End\n");
        printf("3. Add at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Search by Element\n");
        printf("8. Search by Position\n");
        printf("9. Display List\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add at beginning: ");
                scanf("%d", &data);
                head = addbeg(head, data);
                break;
            case 2:
                printf("Enter data to add at end: ");
                scanf("%d", &data);
                head = add_end(head, data);
                break;
            case 3:
                printf("Enter data to add: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                head = add_pos(head, data, pos);
                break;
            case 4:
                head = del_beg(head);
                break;
            case 5:
                head = del_end(head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                head = del_pos(head, pos);
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &data);
                pos = search_by_element(head, data);
                if (pos != -1) {
                    printf("Element %d found at position %d\n", data, pos);
                } else {
                    printf("Element not found in the list.\n");
                }
                break;
            case 8:
                printf("Enter position to search: ");
                scanf("%d", &pos);
                data = search_by_position(head, pos);
                if (data != -1) {
                    printf("Element at position %d is %d\n", pos, data);
                } else {
                    printf("Position out of bounds.\n");
                }
                break;
            case 9:
                print_data(head);
                break;
            case 10:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 10);

    return 0;
}

