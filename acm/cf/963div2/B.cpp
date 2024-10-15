#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int n;
    cin >> n;

    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2)
        {
            odd.emplace_back(x);
        }
        else
        {
            even.emplace_back(x);
        }
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    if (odd.size() == n || even.size() == n)
    {
        cout << 0 << endl;
        return;
    }
    int max_odd = odd.back();
    int min_even = even.front();
    if (even.size() == 1)
    {
        if (min_even > max_odd)
        {
            cout << 2 << endl;
            return;
        }
        else{
            cout << 1 << endl;
            return;
        }
    }
    if (min_even > max_odd)
    {
        cout << even.size() + 1 << endl;
        return;
    }
    for (int i = 0; i < even.size(); i++)
    {
        if (i == even.size() - 1)
        {
            if (min_even > max_odd)
            {
                cout << even.size() + 1 << endl;
                return;
            }
            else{
                cout << even.size() << endl;
                return;
            }
        }
        max_odd += even[i];
        min_even = even[i + 1];
        if (min_even > max_odd)
        {
            cout << even.size() + 1 << endl;
            return;
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