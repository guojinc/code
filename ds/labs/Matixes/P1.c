#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int row;
    int col;
    int val;
} Triplet;
typedef struct {
    Triplet* data;
    int size;
    int row;
    int col;
} Matrix;

void fastTranspose(Matrix *m, Matrix *t){
    int cNum[m->col + 1];
    int cPos[m->col + 1];

    for(int i = 0; i <= m->col; i++){
        cNum[i] = 0;
    }
    for (int i = 1; i <= m->size; i++){
        cNum[m->data[i - 1].col]++;
    }
    cPos[0] = 0;
    for (int i = 1; i <= m->col; i++){
        cPos[i] = cPos[i - 1] + cNum[i - 1];
    }

    for(int i = 0; i < m->size; i++){
        int j = cPos[m->data[i].col]++;
        t->data[j].row = m->data[i].col;
        t->data[j].col = m->data[i].row;
        t->data[j].val = m->data[i].val;
    }
}

void init(Matrix *m, int row, int col){
    m->row = row;
    m->col = col;
    m->size = 0;
    m->data = (Triplet*)malloc(row * col * sizeof(Triplet));
}

void insert(Matrix *m, int row, int col, int val){
    m->data[m->size].row = row;
    m->data[m->size].col = col;
    m->data[m->size].val = val;
    m->size++;
}
int main()
{
    int m ,n;
    int row, col, val;
    scanf("%d %d", &m, &n);
    Matrix M, T;
    init(&M, m, n);
    while(scanf("%d %d %d", &row, &col, &val) != EOF){
        if (row == 0 && col == 0 && val == 0){
            break;
        }
        insert(&M, row, col, val);
    }
    init(&T, n, m); 
    fastTranspose(&M, &T);
    for (int i = 0; i < M.size; i++){
        printf("%d %d %d\n", T.data[i].row, T.data[i].col, T.data[i].val);
    }
    return 0;
}