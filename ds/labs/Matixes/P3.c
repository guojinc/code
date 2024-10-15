#include <stdio.h>
#include <stdlib.h>

typedef struct crosslist {
    int row;
    int col;
    int val;
    struct crosslist *right;
    struct crosslist *down;
} crosslist;

typedef struct {
    crosslist *row_head;
    crosslist *col_head;
    int row;
    int col;
} matrix;

void init(matrix *m, int row, int col) {
    m->row = row;
    m->col = col;
    m->row_head = (crosslist*)malloc(row * sizeof(crosslist));
    m->col_head = (crosslist*)malloc(col * sizeof(crosslist));
    for (int i = 0; i < row; i++) {
        m->row_head[i].right = &m->row_head[i];
    }
    for (int i = 0; i < col; i++) {
        m->col_head[i].down = &m->col_head[i];
    }
}

void insert(matrix *m, int row, int col, int val) {
    crosslist *node = (crosslist*)malloc(sizeof(crosslist));
    node->row = row;
    node->col = col;
    node->val = val;
    
    crosslist *row_ptr = &m->row_head[row];
    while (row_ptr->right != &m->row_head[row] && row_ptr->right->col < col) {
        row_ptr = row_ptr->right;
    }
    node->right = row_ptr->right;
    row_ptr->right = node;
    
    crosslist *col_ptr = &m->col_head[col];
    while (col_ptr->down != &m->col_head[col] && col_ptr->down->row < row) {
        col_ptr = col_ptr->down;
    }
    node->down = col_ptr->down;
    col_ptr->down = node;
}

void print(matrix *m) {
    for (int i = 0; i < m->row; i++) {
        crosslist *ptr = m->row_head[i].right;
        while (ptr != &m->row_head[i]) {
            printf("%d %d %d\n", ptr->row, ptr->col, ptr->val);
            ptr = ptr->right;
        }
    }
}

void add_matrix(matrix *m1, matrix *m2) {
    if (m1->row != m2->row || m1->col != m2->col) {
        printf("ERROR\n");
        return;
    }
    
    matrix result;
    init(&result, m1->row, m1->col);
    
    for (int i = 0; i < m1->row; i++) {
        crosslist *ptr1 = m1->row_head[i].right;
        crosslist *ptr2 = m2->row_head[i].right;
        while (ptr1 != &m1->row_head[i] && ptr2 != &m2->row_head[i]) {
            if (ptr1->col < ptr2->col) {
                insert(&result, i, ptr1->col, ptr1->val);
                ptr1 = ptr1->right;
            } else if (ptr1->col > ptr2->col) {
                insert(&result, i, ptr2->col, ptr2->val);
                ptr2 = ptr2->right;
            } else {
                int sum = ptr1->val + ptr2->val;
                if (sum != 0) {
                    insert(&result, i, ptr1->col, sum);
                }
                ptr1 = ptr1->right;
                ptr2 = ptr2->right;
            }
        }
        while (ptr1 != &m1->row_head[i]) {
            insert(&result, i, ptr1->col, ptr1->val);
            ptr1 = ptr1->right;
        }
        while (ptr2 != &m2->row_head[i]) {
            insert(&result, i, ptr2->col, ptr2->val);
            ptr2 = ptr2->right;
        }
    }
    
    print(&result);
}

int main()
{
    int m, n, t1, t2;
    scanf("%d %d %d %d", &m, &n, &t1, &t2); 
    matrix m1, m2;
    init(&m1, m, n);
    init(&m2, m, n);
    for (int i = 0; i < t1; i++) {
        int row, col, val;
        scanf("%d %d %d", &row, &col, &val);
        insert(&m1, row, col, val);
    }
    for (int i = 0; i < t2; i++ )
    {
        int row, col, val;
        scanf("%d %d %d", &row, &col, &val);
        insert(&m2, row, col, val);
    }
    add_matrix(&m1, &m2);
    free(m1.row_head);
    free(m2.row_head);
    free(m1.col_head);
    free(m2.col_head);
    return 0;
}