#include <stdio.h>
#include <stdlib.h>
typedef struct Graph_List_Node{
    int vertex;
    struct Graph_List_Node *next;
}GN;
typedef struct Queue{
    int *data;
    int head, tail, length;
}Queue;
int bfs(GN *Graph, int start, int end, int *visited){
    visited[start] = 1;
    GN *temp = Graph[start].next;
    Queue q;
    q.data = (int *)malloc(sizeof(int) * 100);
    q.head = 0;
    q.tail = 0;
    q.length = 100;
    q.data[q.tail++] = start;
    while (q.head != q.tail){
        int now = q.data[q.head++];
        GN *temp = Graph[now].next;
        while (temp != NULL){
            if (temp->vertex == end){
                return 1;
            }
            if (visited[temp->vertex] == 0){
                visited[temp->vertex] = 1;
                q.data[q.tail++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int point, edge;
    scanf("%d %d", &point, &edge);
    GN* Graph = (GN *)malloc(sizeof(GN) * point);
    GN* END = (GN *)malloc(sizeof(GN) * point);
    int a[100];
    for (int i = 0; i < point; i++){
        scanf("%d", &a[i]); 
        Graph[i].vertex = i;
        Graph[i].next = NULL;
        END[i].next = &Graph[i];
    }
    for (int i = 0; i < edge; i++){
        int x, y;
        scanf("%d %d", &x, &y);

        int k = 0, l = 0;
        while(a[k] != x) k++;
        while(a[l] != y) l++;
        x = k;
        y = l;
        GN *new = (GN *)malloc(sizeof(GN));
        new->vertex = y;
        new->next = NULL;
        END[k].next->next = new;
        END[k].next = new;
    }
    int start, end;

    scanf("%d %d", &start, &end);
    int k = 0, l = 0;
    while(a[k] != start) k++;
    while(a[l] != end) l++;
    start = k;
    end = l;
    int visited[point];
    for (int i = 0; i < point; i++){
        visited[i] = 0;
    }
    if (bfs(Graph, start, end, visited))
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
}