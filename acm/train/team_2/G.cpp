#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
int Size[100005];
int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    memset(Size, 0, sizeof(Size));
    for (int i = 1; i <= n; i++)
    {
        int num;
        scanf("%d", &num);
        g[num].push_back(i);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     sort(g[i].begin(), g[i].end());
    // }
    while (m--)
    {
        int l, r, p, q;
        scanf("%d%d%d%d", &l, &r, &p, &q);
        if (p < q)
        {
            swap(p, q);
        }
        int ans = 0;
        int cnt = 0;
        auto l_low = lower_bound(g[p].begin(), g[p].end(), l);
        auto l_up = upper_bound(g[p].begin(), g[p].end(), r);
        auto r_low = lower_bound(g[q].begin(), g[q].end(), l);
        auto r_up = upper_bound(g[q].begin(), g[q].end(), r);
        auto temp = r_up - 1;
        for (auto i = l_up - 1; i >= l_low; i--)
        {
            for (auto j = temp; j >= r_low; j--)
            {
                if (*i < *j)
                {
                    cnt++;
                }
                if (*i > *j)
                {
                    ans += cnt;
                    temp = j;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}

