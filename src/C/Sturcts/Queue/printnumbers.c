#include <stdio.h>
#define MAX 100

struct Queue {
    int front, rear;
    int arr[MAX];
};

// Function to initialize queue
void initQueue(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q) {
    return q->front > q->rear;
}

// Function to enqueue an element
void enqueue(struct Queue *q, int value) {
    q->arr[++(q->rear)] = value;
}

// Function to dequeue an element
int dequeue(struct Queue *q) {
    return q->arr[(q->front)++];
}

int main() {
    struct Queue q;
    initQueue(&q);
    int N;

    printf("Enter a number N: ");
    scanf("%d", &N);

    // Enqueue numbers from 1 to N
    for (int i = 1; i <= N; i++) {
        enqueue(&q, i);
    }

    // Dequeue and print each number
    while (!isEmpty(&q)) {
        printf("%d ", dequeue(&q));
    }

    printf("\n");
    return 0;
}
