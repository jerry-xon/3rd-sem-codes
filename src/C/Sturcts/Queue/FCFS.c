#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Process
typedef struct Process {
    int processID;
    int burstTime;  // Time the process needs to complete
    struct Process *next;
} Process;

// Function to create a new process
Process* createProcess(int processID, int burstTime) {
    Process *newProcess = (Process *)malloc(sizeof(Process));
    newProcess->processID = processID;
    newProcess->burstTime = burstTime;
    newProcess->next = NULL;
    return newProcess;
}

// Function to add a process to the end of the queue (enqueue)
void enqueue(Process **rear, Process **front, Process *newProcess) {
    if (*rear == NULL) {
        *rear = newProcess;
        *front = newProcess;
    } else {
        (*rear)->next = newProcess;
        *rear = newProcess;
    }
}

// Function to remove a process from the front of the queue (dequeue)
Process* dequeue(Process **front) {
    if (*front == NULL) {
        return NULL;
    }
    Process *temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *front = NULL;
    }
    return temp;
}

// Function to simulate First-Come, First-Served Scheduling
void FCFScheduling(Process **front) {
    Process *current;
    while (*front != NULL) {
        current = dequeue(front);
        
        // Process the task and print the result
        if (current != NULL) {
            printf("Processing Task %d for %d units of time\n", current->processID, current->burstTime);
            free(current);  // Task completed, free the memory
        }
    }
}

int main() {
    Process *front = NULL, *rear = NULL;

    // Adding some processes to the queue
    enqueue(&rear, &front, createProcess(1, 5));  // Process 1 needs 5 units of time
    enqueue(&rear, &front, createProcess(2, 3));  // Process 2 needs 3 units of time
    enqueue(&rear, &front, createProcess(3, 8));  // Process 3 needs 8 units of time
    enqueue(&rear, &front, createProcess(4, 6));  // Process 4 needs 6 units of time

    printf("Starting First-Come, First-Served Scheduling\n\n");
    FCFScheduling(&front);

    printf("\nAll tasks completed!\n");
    return 0;
}
