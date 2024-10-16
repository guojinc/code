#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char ch) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = ch;
}

char pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    for (i = 0; i < strlen(infix); i++) {
        char ch = infix[i];
        if (isalpha(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();  // 弹出 '('
        } else if (isOperator(ch)) {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }else if (ch == '#')
        {
            continue;
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
int main()
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);
    return 0;
}