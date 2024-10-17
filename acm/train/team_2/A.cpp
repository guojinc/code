#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    queue<pair<float, int>> q;
    q.push({n, k});
    while (!q.empty())
    {
        auto [a, b] = q.front();
        q.pop();
        if ((int)a == 1 || b == 0)
        {
            ans++;
            break;
        }
        if (b == k)
        {
            ans += b + 1;
            q.push({sqrt(int(a)), b - 1});
            continue;
        }
        q.push({sqrt(int(a)), b - 1});
        if (a == (int)a)
        {
            ans++;
        }
        else{
            ans += b + 1;
        }
    }
    cout << ans << endl;
}