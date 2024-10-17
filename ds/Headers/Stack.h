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

typedef struct Stack{
    int size; //size of the Stack
    Node *head;
    Node *tail;
    Node *end;
    void (*print)(struct Stack*);
    void (*clear)(struct Stack*); 
    void (*destructor)(struct Stack*);
    T (*peek)(struct Stack*);
    T (*pop)(struct Stack*);
    void (*push)(struct Stack*, T);
}Stack;

void _constructor(Stack *Stack);
void _add(Stack *Stack, T data);
void _destructor(Stack *Stack);    
T _Remove(Stack *Stack);
void _print(Stack *Stack);
void _Clear(Stack *Stack);
T _Front(Stack *Stack);

// 初始化链表

void _constructor(Stack *Stack) {
    Stack->clear = _Clear;
    Stack->destructor = _destructor;
    Stack->print = _print;
    Stack->push = _add;
    Stack->pop = _Remove;
    Stack->peek = _Front;
    Stack->head = (Node*)malloc(sizeof(Node));
    Stack->tail = (Node*)malloc(sizeof(Node));
    Stack->end = (Node*)malloc(sizeof(Node));
    Stack->end = NULL;
    Stack->head->next = Stack->end;
    Stack->tail->next = Stack->head;
    Stack->size = 0;
}
void _add(Stack *Stack, T data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        return;
    }
    newNode->data = data;
    Stack->tail->next->next = newNode;
    newNode->prev = Stack->tail->next;
    newNode->next = NULL;
    Stack->tail->next = newNode;
    Stack->size++;
    
    return;
}

T _Front(Stack *Stack) {
    return Stack->tail->next->data;
}
T _Remove(Stack *Stack) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (Stack->size == 0)
    {
        printf("栈为空\n");
        return inf;
    }
    node->next = Stack->tail->next;
    T ret = node->next->data;
    Stack->tail->next = node->next->prev;
    if (Stack->size > 1)
    {
        node->next->prev->next = Stack->end;
    }
    free(node->next);
    free(node);
    Stack->size--;
    return ret;
}
void _Clear(Stack *Stack) {
    Node *node = (Node*)malloc(sizeof(Node));
    node = Stack->head;
    while (node != NULL) {
        Node *temp = node;
        node = node->next;
        free(temp);
    }
    Stack->head = NULL;
    Stack->tail = NULL;
    Stack->size = 0;
    free(node);
    return;
}

void _print(Stack *Stack) {

    Node *node = (Node*)malloc(sizeof(Node));
    node->next = Stack->head->next;
    while (node->next->next != NULL) {
        printf("%d ", node->next->data);
        node->next = node->next->next;
    }

    printf("%d\n", node->next->data);
    free(node);
    return;
}

void _destructor(Stack *Stack)
{
    _Clear(Stack);
    return;
}