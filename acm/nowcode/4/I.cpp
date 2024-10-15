#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Pair{
    int l, r;
    bool operator < (const Pair &a) const{
        if (l == a.l)
        {
            return r < a.r;
        }
        return l < a.l;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    vector <Pair> vec(m);
    for (int i = 0; i < m; i++)
    {
        cin >> vec[i].l >> vec[i].r;
    }
    sort(vec.begin(), vec.end());
    int arr[n + 1];
    for (int i = 0; i <= n; i++) arr[i] = i;
    int f = arr[1];
    int l = arr[1];
    for (int i = 0; i < m; i++)
    {
        if (l != vec[i].l)
        {
            arr[l] = f;
            f = arr[vec[i].l];
            l = vec[i].l;   
        }
        if (f + 1 == vec[i].r)
        {
            f = vec[i].r;
            if (i == m - 1)
            {
                arr[l] = f;
            }
        }
    }
    int ans = 0;
    int cnt = 0;
    int ff = arr[1];
    for (int l = 1; l <= n; l++){
        for (int i = l; i <= arr[l]; i++)
        {
            ff = min(ff, arr[i]);
            if (ff == i)
            {
                cnt++;
                ans += cnt;
                if (i != n)
                {
                    ff = arr[i + 1];
                }
                cnt = 0;
                break;
            }
        cnt++;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios
    solve();
}