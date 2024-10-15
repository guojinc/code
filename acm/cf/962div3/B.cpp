#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int n, k;
    cin >> n >> k;
    string in;
    for (int i = 0; i < n; i++)
    {
        cin >> in;
        for (int j = 0; j < n; j++)
        {
            if (i % k == 0 && j % k == 0)
            {
                cout << in[j];
            }
            if (j == n - 1 &&  i % k == 0)
            {
                cout << endl;
            }
        }
    }

}


signed main()
{
    ios
    int t;  
    cin >> t;
    while (t--)
    {
        solve();
    }
}