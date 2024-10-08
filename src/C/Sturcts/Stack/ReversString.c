#include <stdio.h>
#include <string.h>
#define MAX 100

struct Stack {
    int top;
    char arr[MAX];
};

// Function to initialize stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Function to push an element onto the stack
void push(struct Stack *s, char ch) {
    s->arr[++(s->top)] = ch;
}

// Function to pop an element from the stack
char pop(struct Stack *s) {
    return s->arr[(s->top)--];
}

// Function to reverse a string using stack
void reverseString(char str[]) {
    struct Stack s;
    initStack(&s);
    int n = strlen(str);

    // Push all characters of the string onto the stack
    for (int i = 0; i < n; i++) {
        push(&s, str[i]);
    }

    // Pop all characters from the stack and update the string
    for (int i = 0; i < n; i++) {
        str[i] = pop(&s);
    }
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    gets(str);  // Take input string

    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}
