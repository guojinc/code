#include "../Headers/Stack.h"

int isbracket(char c)
{
    return (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']');
}
int ismatch(char a, char b)
{
    return ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'));
}
int main(int argc, char* argv)
{
    char in[256];
    Stack q;
    _constructor(&q);
    fgets(in,256,stdin);
    int len = strlen(in);
    for (int i = 0; i < len; i++)
    {
        if (isbracket(in[i]))
        {
            if (q.size != 0)
            {
                if (ismatch(q.peek(&q), in[i]))
                {
                    q.pop(&q);
                }
                 else
                {
                    q.push(&q, in[i]);
                }
            }
            else
            {
                q.push(&q, in[i]);
            }
        }
    }
    if (q.size != 0)
    {
        printf("no");
    }
    else
    {
        printf("yes");
    }
    q.destructor(&q);
}