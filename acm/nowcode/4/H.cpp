#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int n;
    cin >> n;
    set <int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    int MIN = 1e18;
    if (s.size() == 1)
    {
        cout << 0 << endl;
        return;
    }
    if (s.size() == 2)
    {
        cout << *s.rbegin() - *s.begin() << endl;
        return;
    }
    while (s.size() > 2)
    {
        auto a = s.begin();
        auto b = ++s.begin();
        MIN = min(MIN, *b - *a);
        auto k = ++b;
        b = --b;
        int c = *b - *a;
        int d = (*k - *b) / c * c + *b;

        s.erase(a);
        s.erase(b);
        s.insert(d);
        s.insert(d + c);
    }
    MIN = min(MIN, *s.rbegin() - *s.begin());
    cout << MIN << endl;
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