#include "header.h"
#include <stdio.h>

int main() {
    ProcessQueue pq;
    int choice, time, time_slice;

    printf("Enter the fixed time slice for each process: ");
    scanf("%d", &time_slice);

    // Initialize the queue
    init_queue(&pq);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Process\n");
        printf("2. Execute\n");
        printf("3. Display Processes\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter process time: ");
                scanf("%d", &time);
                insert_process(&pq, time);
                break;

            case 2:
                execute(&pq, time_slice);
                break;

            case 3:
                display(&pq);
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Initialize the process queue
void init_queue(ProcessQueue* pq) {
    pq->head = NULL;
}

// Insert a new process into the queue with a specified time
void insert_process(ProcessQueue* pq, int time) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->time = time;
    newNode->next = NULL;

    if (pq->head == NULL) {
        pq->head = newNode;
        newNode->next = pq->head;  // Circular link
    } else {
        Node* temp = pq->head;
        while (temp->next != pq->head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = pq->head;  // Circular link
    }
}

// Execute a process from the front of the queue
void execute(ProcessQueue* pq, int time_slice) {
    if (pq->head == NULL) {
        printf("No processes in the queue.\n");
        return;
    }

    Node* temp = pq->head;
    pq->head = pq->head->next;  // Move head to the next process

    temp->time -= time_slice;  // Subtract the time slice

    if (temp->time <= 0) {
        printf("Process completed (time %d executed).\n", temp->time + time_slice);
        free(temp);  // Process is completed, free the memory
    } else {
        // If there is remaining time, insert it back to the end
        printf("Process remaining time: %d\n", temp->time);
        insert_process(pq, temp->time);
        free(temp);  // Free the original node
    }
}

// Display all processes in the queue
void display(ProcessQueue* pq) {
    if (pq->head == NULL) {
        printf("The queue is empty.\n");
        return;
    }

    Node* temp = pq->head;
    do {
        printf("Process with time: %d -> ", temp->time);
        temp = temp->next;
    } while (temp != pq->head);
    printf("(head)\n");
}

// Check if the queue is empty
int is_empty(ProcessQueue* pq) {
    return pq->head == NULL;
}
