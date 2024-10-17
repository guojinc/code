#include <stdio.h>
#include <stdlib.h>

typedef char T;

typedef struct Priority_QueueNode {
    T data;
    int priority;
    struct Priority_QueueNode* next;
} Priority_QueueNode;

typedef struct Priority_Queue {
    Priority_QueueNode* head;
    int size;
    void (*enqueue)(struct Priority_Queue*, int, int);
    T (*dequeue)(struct Priority_Queue*);
    void (*print)(struct Priority_Queue*);
    void (*clear)(struct Priority_Queue*);
    void (*destructor)(struct Priority_Queue*);
    T (*front)(struct Priority_Queue*);
} Priority_Queue;


void _constructor(Priority_Queue* PriorityQueue);
void _enqueue(Priority_Queue* PriorityQueue, int data, int priority);
void _destructor(Priority_Queue* PriorityQueue);
T _dequeue(Priority_Queue* PriorityQueue);
void _print(Priority_Queue* PriorityQueue);
void _clear(Priority_Queue* PriorityQueue);
T _front(Priority_Queue* PriorityQueue);


void _constructor(Priority_Queue* Priority_Queue) {
    Priority_Queue->enqueue = _enqueue;
    Priority_Queue->dequeue = _dequeue;
    Priority_Queue->print = _print;
    Priority_Queue->clear = _clear;
    Priority_Queue->destructor = _destructor;
    Priority_Queue->head = (Priority_QueueNode*)malloc(sizeof(Priority_QueueNode));
    Priority_Queue->head->next = NULL;
    Priority_Queue->size = 0;
}

void _enqueue(Priority_Queue* Priority_Queue, int data, int priority) {
    Priority_QueueNode* newNode = (Priority_QueueNode*)malloc(sizeof(Priority_QueueNode));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        return;
    }
    newNode->data = data;
    newNode->priority = priority;
    Priority_QueueNode* temp = Priority_Queue->head;
    while (temp->next != NULL && temp->next->priority < priority) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    Priority_Queue->size++;
}

T _dequeue(Priority_Queue* Priority_Queue) {
    if (Priority_Queue->head->next == NULL) {
        printf("队列为空\n");
        return -1;
    }
    Priority_QueueNode* temp = Priority_Queue->head->next;
    Priority_Queue->head->next = temp->next;
    int data = temp->data;
    free(temp);
    Priority_Queue->size--;
    return data;
}

void _print(Priority_Queue* Priority_Queue) {
    Priority_QueueNode* temp = Priority_Queue->head->next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void _clear(Priority_Queue* Priority_Queue) {
    Priority_QueueNode* temp = Priority_Queue->head->next;
    while (temp != NULL) {
        Priority_QueueNode* node = temp;
        temp = temp->next;
        free(node);
    }
    Priority_Queue->head->next = NULL;
    Priority_Queue->size = 0;
}

T _front(Priority_Queue* Priority_Queue) {
    if (Priority_Queue->head->next == NULL) {
        printf("队列为空\n");
        return -1;
    }
    return Priority_Queue->head->next->data;
}

