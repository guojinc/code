#include <bits/stdc++.h>

using namespace std;

int mod = 998244353;

int main()
{
    int n, k;
    cin >> n >> k;
    long long ans = 1;
    if (n < k)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= k; i++)
    {
        ans = ans * i % mod;
    }
    cout << (n - k) * ans % mod << endl;
}