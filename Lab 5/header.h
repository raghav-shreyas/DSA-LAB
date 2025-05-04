#define PROCESS_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int time;            // Time required for the process
    struct Node* next;   // Pointer to the next process in the list
};

typedef struct Node Node;

typedef struct {
    Node* head;  // Pointer to the first node in the circular linked list
} ProcessQueue;

// Function declarations
void init_queue(ProcessQueue* pq);
void insert_process(ProcessQueue* pq, int time);
void execute(ProcessQueue* pq, int time_slice);
void display(ProcessQueue* pq);
int is_empty(ProcessQueue* pq);

