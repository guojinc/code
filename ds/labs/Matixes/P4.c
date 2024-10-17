#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int val;
} Triplet;

typedef struct {
    Triplet* data;
    int row;
    int col;
    int size;
    int capacity;
} SparseMatrix;

void init(SparseMatrix* sm, int capacity) {
    sm->data = (Triplet*)malloc(capacity * sizeof(Triplet));
    sm->size = 0;
    sm->capacity = capacity;
}   

void add(SparseMatrix* sm, int row, int col, int val) {
    if (sm->size >= sm->capacity) {
        sm->capacity *= 2;
        sm->data = (Triplet*)realloc(sm->data, sm->capacity * sizeof(Triplet));
    }
    sm->data[sm->size].row = row;
    sm->data[sm->size].col = col;
    sm->data[sm->size].val = val;
    sm->size++;
}   

void print(SparseMatrix* sm) {
    for (int i = 0; i < sm->size; i++) {
        printf("%d %d %d\n", sm->data[i].row, sm->data[i].col, sm->data[i].val);
    }
}
SparseMatrix fastTranspose(SparseMatrix *m){
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

    SparseMatrix t;
    init(&t, m->size);
    t.row = m->col;
    t.col = m->row;
    t.size = m->size;
    for(int i = 0; i < m->size; i++){
        int j = cPos[m->data[i].col]++;
        t.data[j].row = m->data[i].col;
        t.data[j].col = m->data[i].row;
        t.data[j].val = m->data[i].val;
    }
    return t;
}


SparseMatrix Mutiple_Matrix(SparseMatrix sm1, SparseMatrix sm) {
    SparseMatrix sm2 = fastTranspose(&sm);
    SparseMatrix result;
    init(&result, sm1.size + sm2.size);
    int cNum1[sm1.row + 1];
    int cPos1[sm1.row + 1];

    for(int i = 0; i <= sm1.row; i++){
        cNum1[i] = 0;
    }
    for (int i = 1; i <= sm1.size; i++){
        cNum1[sm1.data[i - 1].row]++;
    }
    cPos1[0] = 0;
    for (int i = 1; i <= sm1.row; i++){
        cPos1[i] = cPos1[i - 1] + cNum1[i - 1];
    }
    int cNum2[sm2.row + 1];
    int cPos2[sm2.row + 1];

    for(int i = 0; i <= sm2.row; i++){
        cNum2[i] = 0;
    }
    for (int i = 1; i <= sm2.size; i++){
        cNum2[sm2.data[i - 1].row]++;
    }
    cPos2[0] = 0;
    for (int i = 1; i <= sm2.row; i++){
        cPos2[i] = cPos2[i - 1] + cNum2[i - 1];
    }

    for (int i = 0; i < sm1.row; i++) {
        for (int j = 0; j < sm2.row; j++) {
            int sum = 0;
            for (int k = 0; k < cNum1[i + 1]; k++) {
                for (int l = 0; l < cNum2[j + 1]; l++)
                {
                    if (sm1.data[cPos1[i + 1] + k].col == sm2.data[cPos2[j + 1] + l].col)
                        sum += (sm1.data[cPos1[i + 1] + k].val * sm2.data[cPos2[j + 1] + l].val);
                }
            }
            if (sum != 0) {
                add(&result, i + 1, j + 1, sum);
            }
        }
    }
    
    
    return result;
}

int main()
{
    int m, n;
    int row, col, val;
    scanf("%d %d", &m, &n);
    SparseMatrix sm1, sm2;
    sm1.row = m;
    sm1.col = n;
    init(&sm1, m * n);
    while(scanf("%d %d %d", &row, &col, &val) != EOF){
        if (row == 0 && col == 0 && val == 0){
            break;
        }
        add(&sm1, row, col, val);
    }
    scanf("%d %d", &m, &n);
    init(&sm2, m * n);
    sm2.row = m;
    sm2.col = n;
    while(scanf("%d %d %d", &row, &col, &val) != EOF){
        if (row == 0 && col == 0 && val == 0){
            break;
        }
        add(&sm2, row, col, val);
    }
    SparseMatrix result = Mutiple_Matrix(sm1, sm2);
    print(&result);
}
