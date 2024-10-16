#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct code
{
    char data;
    char code[100];
} Code;

typedef struct Huffman_Tree_Node
{
    char data;
    int weight;
    struct HNode *left;
    struct HNode *right;
} HNode;

typedef struct Priority_Queue
{
    HNode *data;
    int priority;
    int size;
    struct Priority_Queue *next;
} P_Q;

void enqueue(P_Q* Q, HNode* data, int priority)
{
    P_Q* newNode = (P_Q*)malloc(sizeof(P_Q));
    if (newNode == NULL)
    {
        printf("内存分配失败\n");
        return;
    }
    newNode->data = data;
    newNode->priority = priority;
    P_Q* temp = Q;
    while (temp->next != NULL && temp->next->priority <= priority)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    Q->size++;
}

HNode* dequeue(P_Q* Q)
{
    if (Q->next == NULL)
    {
        printf("队列为空\n");
        return NULL;
    }
    P_Q* temp = Q->next;
    Q->next = temp->next;
    HNode* data = temp->data;
    free(temp);
    Q->size--;
    return data;
}

HNode* Huffman(P_Q* Q)
{
    HNode* root;
    while (Q->size > 1)
    {
        HNode* left = dequeue(Q);
        HNode* right = dequeue(Q);
        HNode* parent = (HNode*)malloc(sizeof(HNode));
        parent->data = '\0';
        parent->weight = left->weight + right->weight;
        parent->left = left;
        parent->right = right;
        enqueue(Q, parent, parent->weight);
    }
    root = dequeue(Q);
    return root;
}

int cidx = 0;
void coding(HNode* root, Code* code, int index, char* str)
{
    if (root->left == NULL && root->right == NULL)
    {
        code[cidx].data = root->data;
        str[index] = '\0';
        strcpy(code[cidx].code, str);\
        cidx++;
        return;
    }
    if (root->left != NULL)
    {
        str[index] = '0';
        coding(root->left, code, index + 1, str);
        str[index] = '\0';
    }
    if (root->right != NULL)
    {
        str[index] = '1';
        coding(root->right, code, index + 1, str);
        str[index] = '\0';
    }
}

char* decode(HNode* root, char* str)
{
    HNode* temp = root;
    char* Str = (char*)malloc(sizeof(char) * 100);
    int index = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '0')
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
        if (temp->left == NULL && temp->right == NULL)
        {
            Str[index] = temp->data;
            index++;
            temp = root;
        }
    }
    Str[index] = '\0';
    return Str;
}

int main()
{
    P_Q Q;
    Q.next = NULL;
    Q.size = 0;
    int n;
    scanf("%d ", &n);
    int arr[n];
    char carr[n];
    char str[100];
    
    for (int i = 0; i < n; i++)
    {
        scanf("%c ", &carr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &arr[i]);
    }
    scanf("%s", &str);
    HNode Nodes[n];
    for (int i = 0; i < n; i++)
    {
        Nodes[i].data = carr[i];
        Nodes[i].weight = arr[i];
        Nodes[i].left = NULL;
        Nodes[i].right = NULL;
    }
    for (int i = 0; i < n; i++)
    {
        enqueue(&Q, &Nodes[i], Nodes[i].weight);
    }
    HNode *root;
    root = Huffman(&Q);
    Code code[n];
    char S[100];
    char ss[100];
    ss[0] = '\0';
    coding(root, code, 0, S);
    for (int i = 0; str[i] != '\0'; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (str[i] == code[j].data)
            {
                strcat(ss, code[j].code);
                printf("%s",code[j].code);
                break;
            }
        }   
    }
    
    char* Str = decode(root, ss);
    printf("\n%s", Str);
}

