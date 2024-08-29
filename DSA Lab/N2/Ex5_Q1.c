#include <stdio.h>
#include <stdlib.h>

// Creating node structure
struct node {
    int data;
    struct node *link;
};

//function to print data of the lsit
void print_data(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

//Count total number of nodes function 
void count_of_node(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        int count = 0;
        struct node *ptr = head;
        while (ptr != NULL) {
            count++;
            ptr = ptr->link;
        }
        printf("Total number of nodes are: %d\n", count);
    }
}

//delete node from begining function
struct node* del_beg(struct node *head) {
    if (head == NULL) {
        printf("List is already empty.\n");
    } else {
        struct node *temp = head;
        head = head->link;
        free(temp);
        printf("Node at the beginning deleted.\n");
    }
    return head;
}

//add new node at begining function
struct node* add_beg(struct node *head, int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = head;
    head = ptr;
    printf("Node added at the beginning.\n");
    return head;
}

//add new node at the end of the list function
void add_at_end(struct node *head, int data) {
    struct node *ptr = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = temp;
    printf("Node added at the end.\n");
}

//delete node from the end of the list function
struct node *del_end(struct node *head) {
    if (head == NULL) {
        printf("List is already empty.\n");
    } else if (head->link == NULL) {
        free(head);
        head = NULL;
        printf("Node at the end deleted.\n");
    } else {
        struct node *temp = head;
        struct node *temp2 = head;
        while (temp->link != NULL) {
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = NULL;
        free(temp);
        printf("Node at the end deleted.\n");
    }
    return head;
}

//add node at a position function
void add_at_pos(struct node *head, int data, int pos) {
    struct node *ptr = head;
    struct node *ptr2 = (struct node *)malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;

    pos--;
    while (pos != 1) {
        ptr = ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
    
}

//search element position function
void search_element(struct node *head, int data) {
    struct node *ptr = head;
    int pos = 1;
    while (ptr != NULL) {
        if (ptr->data == data) {
            printf("Element %d found at position %d.\n", data, pos);
            return;
        }
        ptr = ptr->link;
        pos++;
    }
    printf("Element %d not found in the list.\n", data);
}

//search elemment with position function
void get_position(struct node *head, int pos) {
    struct node *ptr = head;
    int current_pos = 1;
    while (ptr != NULL) {
        if (current_pos == pos) {
            printf("Element at position %d is %d.\n", pos, ptr->data);
            return;
        }
        ptr = ptr->link;
        current_pos++;
    }
    printf("Position %d is out of bounds.\n", pos);
}

//main function
int main() {
    struct node *head = NULL;
    int choice, data, pos;

//while loop to print menu
    while (1) {
        printf("\nMenu:\n");
        printf("1. Print data\n");
        printf("2. Count nodes\n");
        printf("3. Add node at beginning\n");
        printf("4. Add node at end\n");
        printf("5. Add node at specific position\n");
        printf("6. Delete node from beginning\n");
        printf("7. Delete node from end\n");
        printf("8. Search for an element\n");
        printf("9. Get element at specific position\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


//switch case to make choice function with other function calls
        switch (choice) {
            case 1:
                print_data(head);
                break;
            case 2:
                count_of_node(head);
                break;
            case 3:
                 printf("Enter data to add at beginning: ");
                scanf("%d", &data);
                head = add_beg(head, data);
                break;
            case 4:
                printf("Enter data to add at end: ");
                scanf("%d", &data);
                if (head == NULL) {
                    head = add_beg(head, data);
                } else {
                    add_at_end(head, data);
                }
                break;
            case 5:
                printf("Enter position to add node: ");
                scanf("%d", &pos);
                if (pos == 1) {
                    printf("Enter data to add at position %d: ", pos);
                    scanf("%d", &data);
                    head = add_beg(head, data);
                    printf("Node added at position %d.\n", pos);
                } else {
                    printf("Enter data to add at position %d: ", pos);
                    scanf("%d", &data);
                    add_at_pos(head, data, pos);
                    printf("Node added at position %d.\n", pos);
                }
                break;
            case 6:
                head = del_beg(head);
                break;
            case 7:
                head = del_end(head);
                break;
            case 8:
                printf("Enter the element to search: ");
                scanf("%d", &data);
                search_element(head, data);
                break;
            case 9:
                printf("Enter position to get element: ");
                scanf("%d", &pos);
                get_position(head, pos);
                break;
            case 10:
                printf("Exiting...");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
