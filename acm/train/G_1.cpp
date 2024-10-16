#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<set<int>> dsu;

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
        for (int i = 0; i < n; i++)
        {
            set<int> temp;
            temp.insert(i);
            dsu.push_back(temp);
        }
        
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
        int res = d.Size[d.find(mess[mess.size() - 1])];
        printf("Case #%d: %d\n", cas++, res);
        getchar();

    }
}