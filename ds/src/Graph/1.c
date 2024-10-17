#include <stdio.h>
#include <stdlib.h>
typedef struct Graph_List_Node{
    int vertex;
    struct Graph_List_Node *next;
}GN;

int dfs(GN *Graph, int start, int end, int *visited){
    if (visited[start] == 1){
        return 0;
    }
    visited[start] = 1;
    GN *temp = Graph[start].next;
    while (temp != NULL){
        if (temp->vertex == end){
            return 1;
        }
        int now = temp->vertex; 
        temp = temp->next;
        if (dfs(Graph, now, end, visited))
        {
            return 1;
        }
    }
    return 0;
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
    if (dfs(Graph, start, end, visited))
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
}