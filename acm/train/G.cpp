#include <iostream>
#include <vector>
#include <numeric>
#include <cstdio>

using namespace std;
int id;
class dsu{
public:
    vector<int>pa;
    dsu(int n, int m):pa(2 * n + m){
        iota(pa.begin(), pa.begin() + n, n);
        iota(pa.begin() + n, pa.end(), n);
    }
    int find(int x)
    {
        if (x != pa[x])
        {
            pa[x] = find(pa[x]);
        }
        return pa[x];
    }
    void unite(int a, int b)
    {
        int x = find(a);
        int y = find(b);
        if (x == y)
        {
            return;
        }
        
        pa[y] = x;
    }
    void remove(int x)
    {
        pa[x] = id++;
    }
    ~dsu()
    {
        pa.clear();
    }
};


int main()
{
    int cas = 1;
    while (1)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        if (n == 0 && m == 0)
        {
            break;
        }
        dsu d(n, m);
        id = 2 * n;
        while (m--)
        {
            char op;
            int x, y;
            scanf(" %c%d", &op, &x);
            if (op == 'M')
            {   
                scanf("%d", &y);
                d.unite(x, y);
            }    
            if (op ==  'S')
            {
                d.remove(x);
            }
        }
        int root[1000050] = {0};
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (root[d.find(i)] == 0)
            {
                res++;
                root[d.find(i)] = 1;
            }
        }
        printf("Case #%d: %d\n", cas++, res);
        getchar();

    }
}