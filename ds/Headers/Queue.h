#pragma once
#include <stdio.h>
#include <stdlib.h>
#define inf 1 << 31;

typedef int T;
typedef struct Node{
    T data;
    struct Node *prev;
    struct Node *next;
}Node;

typedef struct Queue{
    int size; //size of the Queue
    Node *head;
    Node *tail;
    Node *end;
    void (*print)(struct Queue*);
    void (*clear)(struct Queue*); 
    void (*destructor)(struct Queue*);
    T (*front)(struct Queue*);
    T (*dequeue)(struct Queue*);
    void (*enqueue)(struct Queue*, T);
}Queue;

void _constructor(Queue *Queue);
void _add(Queue *Queue, T data);
void _destructor(Queue *Queue);    
T _Remove(Queue *Queue);
void _print(Queue *Queue);
void _Clear(Queue *Queue);
T _Front(Queue *Queue);

// 初始化链表

void _constructor(Queue *Queue) {
    Queue->clear = _Clear;
    Queue->destructor = _destructor;
    Queue->print = _print;
    Queue->enqueue = _add;
    Queue->dequeue = _Remove;
    Queue->front = _Front;
    Queue->head = (Node*)malloc(sizeof(Node));
    Queue->tail = (Node*)malloc(sizeof(Node));
    Queue->end = (Node*)malloc(sizeof(Node));
    Queue->end = NULL;
    Queue->head->next = Queue->end;
    Queue->tail->next = Queue->head;
    Queue->size = 0;
}
void _add(Queue *Queue, T data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        return;
    }
    newNode->data = data;
    Queue->tail->next->next = newNode;
    newNode->prev = Queue->tail->next;
    newNode->next = NULL;
    Queue->tail->next = newNode;
    Queue->size++;
    
    return;
}

T _Front(Queue *Queue) {
    return Queue->head->next->data;
}
T _Remove(Queue *Queue) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (Queue->size == 0)
    {
        printf("队列为空\n");
        return inf;
    }
    node->next = Queue->head->next;
    T ret = node->next->data;
    Queue->head->next = node->next->next;
    if (Queue->size > 1)
    {
        node->next->next->prev = Queue->head;
    }
    free(node->next);
    free(node);
    Queue->size--;
    return ret;
}
void _Clear(Queue *Queue) {
    Node *node = (Node*)malloc(sizeof(Node));
    node = Queue->head;
    while (node != NULL) {
        Node *temp = node;
        node = node->next;
        free(temp);
    }
    Queue->head = NULL;
    Queue->tail = NULL;
    Queue->size = 0;
    free(node);
    return;
}

void _print(Queue *Queue) {

    Node *node = (Node*)malloc(sizeof(Node));
    node->next = Queue->head->next;
    while (node->next->next != NULL) {
        printf("%d ", node->next->data);
        node->next = node->next->next;
    }

    printf("%d\n", node->next->data);
    free(node);
    return;
}

void _destructor(Queue *Queue)
{
    _Clear(Queue);
    return;
}