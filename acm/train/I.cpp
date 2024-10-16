#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>

using namespace std;

int n, t;
struct range{
    int l, r;
    int id;
};

struct dsu{
    vector<range>pa;
    vector<int>Size;
    dsu(int n)
    {
        pa = vector<range>(n * 2);
        for (int i = 0; i < n; i++)
        {
            int l, r;
            cin >> l >> r;
            pa[i] = {l, r, i};
        }
        for (int i = n; i < n * 2; i++)
        {
            pa[i] = pa[i - n];
        }
        Size = vector<int>(n * 2, 1);
    }
    int find(int x)
    {
        if (pa[x].id == x)
        {
            return x;
        }
        return pa[x].id = find(pa[x].id);
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return;
        }
        if (Size[x] < Size[y])
        {
            swap(x, y);
        }
        Size[x] += Size[y];
        pa[x].l = min(pa[x].l, pa[y].l);
        pa[x].r = max(pa[x].r, pa[y].r);
        pa[y].id = x;
    }
    void remove(int x)
    {
        Size[find(x)]--;
        pa[x].id = x;
    }
};



int main()
{
    cin >> n >> t;
    dsu a(n);
    
}