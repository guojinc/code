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

typedef struct List{
    int size; //size of the list
    Node *head;
    Node *tail;
    Node *end;
    void (*print)(struct List*);
    void (*clear)(struct List*);
    void (*destructor)(struct List*);
    void (*sort)(struct List*);
    void (*insert)(struct List*, int, T);
    void (*Remove)(struct List*, int);
    void (*add)(struct List*, T);
    T (*get_elem)(struct List*, int );
    void (*change_elem)(struct List*, int, T);
}List;

T _get_elem(List *list, int index);
void _constructor(List *list);
void _add(List *list, T data);
void _destructor(List *list);    
void _insert(List *list, int index, T data);
void _sort(List *list);
void _Remove(List *list, int index);
void _print(List *list);
void _Clear(List *list);
void _change_elem(List* list, int index, T elem);

// 初始化链表
T _get_elem(List *list, int index) {
    if (index >= list->size || index < 0)
    {
        printf("Index out of range\n");
        return inf;
    }
    Node *current = (Node*)malloc(sizeof(Node));
    current = list->head;

    for (int i = 0; i < index + 1; i++)
    {
        current = current->next;
    }
    return current->data;
}
void _constructor(List *list) {
    list->clear = _Clear;
    list->destructor = _destructor;
    list->print = _print;
    list->sort = _sort;
    list->add = _add;
    list->insert = _insert;
    list->Remove = _Remove;
    list->change_elem = _change_elem;
    list->get_elem = _get_elem;
    list->head = (Node*)malloc(sizeof(Node));
    list->tail = (Node*)malloc(sizeof(Node));
    list->end = (Node*)malloc(sizeof(Node));
    list->end = NULL;
    list->head->next = list->end;
    list->tail->next = list->head;
    list->size = 0;
}
void _add(List *list, T data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        return;
    }
    newNode->data = data;
    list->tail->next->next = newNode;
    newNode->prev = list->tail->next;
    newNode->next = NULL;
    list->tail->next = newNode;
    list->size++;
    
    return;
}

void _insert(List *list, int index, T data) {
    if (index < 0 || index > list->size)
    {
        printf("index out of range\n");
        return;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        return;
    }
    newNode->data = data;
    Node *node = list->head;
    for (int i = 0; i < index && node->next != NULL; i++) {
        node = node->next;
    }
    newNode->next = node->next;
    newNode->prev = node;
    node->next = newNode;
    list->size++;
    
    return;
}

void _Remove(List *list, int index) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (index < 0 || index >= list->size)
    {
        printf("index out of range\n");
        return;
    }

    node->next = list->head;
    for (int i = 0; i < index; i++) {
        node->next = node->next->next;
    }
    node->next->next = node->next->next->next;
    if (index == 0)
    {
        node->next->next->prev = list->head;
    }
    else
    {
        node->next->next->prev = node->next;
    }
    free(node);
    list->size--;
    return;
}
void _change_elem(List* list, int index, T elem)
{
    Node *node = (Node*)malloc(sizeof(Node));
    if (index < 0 || index >= list->size)
    {
        printf("index out of range\n");
        return;
    }
    node->next = list->head;
    for (int i = 0; i < index + 1; i++) {
        node->next = node->next->next;
    }
    node->next->data = elem;
    return;
}
void _Clear(List *list) {
    Node *node = (Node*)malloc(sizeof(Node));
    node = list->head;
    while (node != NULL) {
        Node *temp = node;
        node = node->next;
        free(temp);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    free(node);
    return;
}
void _sort(List *list)
{
    // 冒泡排序
    T* arr = (T*)malloc(sizeof(T) * list->size);
    Node* node = (Node*)malloc(sizeof(Node));
    node->next=list->head->next;
    for (int i = 0; i < list->size; i++) {
        arr[i] = node->next->data;
        node->next = node->next->next;
    }
    for (int i = 0; i < list->size - 1; i++) {
        for (int j = 0; j < list->size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    node->next = list->head->next;
    for (int i = 0; i < list->size; i++) {
        node->next->data = arr[i];
        node->next = node->next->next;
    }
    free(arr);
    free(node);
    return;
}

void _print(List *list) {

    Node *node = (Node*)malloc(sizeof(Node));
    node->next = list->head->next;
    while (node->next->next != NULL) {
        printf("%d ", node->next->data);
        node->next = node->next->next;
    }

    printf("%d\n", node->next->data);
    free(node);
    return;
}

void _destructor(List *list)
{
    _Clear(list);
    return;
}