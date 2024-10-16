#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

signed main()
{
    ios
    int n, k;
    cin >> n >> k;
    if (n % 2 == 0 && n / 2 == k)
    {
        cout << n << endl;
        return 0;
    }
    if (k * 2 > n)
    {
        k = n - k;
    }
    cout << n * k + 1 << endl;
}