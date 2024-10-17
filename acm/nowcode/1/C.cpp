#include <bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
const int mod = 1000000007;
int suffix[100];
int a[100];

signed main()
{
    ios
    int n;
    cin >> n;
    int end = 0;
    int suf = 0;
    int sum = 0;
    suffix[0] = 0;
    while (n--)
    {
        int t, v;
        cin >> t >> v;
        end -= t;
        end++;
        suf = (suffix[end + t - 1] - suffix[end - 1] - v) ;
        int cal = 0;
        int S = 0;
        for (int i = end + t - 1; i > end - 1; i--)
        {
            S = (S + a[i]) ;
            cal = (cal + S) ;
        }
        a[end] = v;
        suffix[end] = (suffix[end - 1] + v) ;
        sum = (sum - suf * (end - 1) - cal + v) % mod;
        cout << sum << endl;
    }
}