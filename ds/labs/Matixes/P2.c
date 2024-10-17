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

SparseMatrix add_matrices(SparseMatrix sm1, SparseMatrix sm2) {
    SparseMatrix result;
    init(&result, sm1.size + sm2.size);
    
    int i = 0, j = 0;
    while (i < sm1.size && j < sm2.size) {
        if (sm1.data[i].row < sm2.data[j].row || (sm1.data[i].row == sm2.data[j].row && sm1.data[i].col < sm2.data[j].col)) {
            add(&result, sm1.data[i].row, sm1.data[i].col, sm1.data[i].val);
            i++;
        } else if (sm1.data[i].row > sm2.data[j].row || (sm1.data[i].row == sm2.data[j].row && sm1.data[i].col > sm2.data[j].col)) {
            add(&result, sm2.data[j].row, sm2.data[j].col, sm2.data[j].val);
            j++;
        } else {
            int sum = sm1.data[i].val + sm2.data[j].val;
            if (sum != 0) {
                add(&result, sm1.data[i].row, sm1.data[i].col, sum);
            }
            i++;
            j++;
        }
    }
    
    while (i < sm1.size) {
        add(&result, sm1.data[i].row, sm1.data[i].col, sm1.data[i].val);
        i++;
    }
    
    while (j < sm2.size) {
        add(&result, sm2.data[j].row, sm2.data[j].col, sm2.data[j].val);
        j++;
    }
    
    return result;
}


int main()
{
    int m, n;
    int t1, t2;
    scanf("%d %d %d %d", &m, &n, &t1, &t2);
    SparseMatrix sm_1, sm_2;
    init(&sm_1, 100);
    init(&sm_2, 100);
    for (int i = 0; i < t1; i++) {
        int row, col, val;
        scanf("%d %d %d", &row, &col, &val);
        add(&sm_1, row, col, val);
    }
    for (int i = 0; i < t2; i++) {
        int row, col, val;
        scanf("%d %d %d", &row, &col, &val);
        add(&sm_2, row, col, val);
    }
    SparseMatrix sm_sum = add_matrices(sm_1, sm_2);
    for (int i = 0; i < sm_sum.size; i++) {
        printf("%d %d %d\n", sm_sum.data[i].row, sm_sum.data[i].col, sm_sum.data[i].val);
    }
}

