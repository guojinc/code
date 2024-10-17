#include <bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    ios
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (n <= k)
        {
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        queue<pair<int, int>> q;
        q.push({n, 1});
        while (!q.empty())
        {
            auto [a, b] = q.front();
            q.pop();
            if (a <= k)
            {
                ans += b;
                continue;
            }
            if (a / k < k)
            {
                ans += b;
                if (a % k == 0 || a % k == 1)
                {
                    ans += a / k * b;
                }
                else{
                    ans += (a / k + 1) * b;
                }
                continue;
            }
            ans += b;
            if (a % k != 0)
            {
                q.push({n / k, b * (k - 1)});
                q.push({n % k + n / k, b});
            }
            else {
                q.push({n / k, k * b});
            }
        }
        cout << ans << endl;
    }
}