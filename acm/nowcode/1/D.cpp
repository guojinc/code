#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int sum[1000000];
const int mod = 2097152;

signed main()
{
    ios
    int n;
    cin >> n;
    int end = 0;
    sum[0] = 0;
    while (n--)
    {
        int t, v;
        cin >> t >> v;
        end -= t;
        end++;
        sum[end] = sum[end - 1] + v;
        int ans = 0;
        for (int i = 1; i <= end; i++)
        {
            ans = ans ^ sum[i];
        }
        cout << ans << endl;
    }
}