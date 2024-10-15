#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
typedef pair<int, int> pii;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int n, k;
    cin >> n >> k;
    // vector<int> powofk(30);
    // powofk[0] = 1;
    // for (int i = 1; i < 30; i++)
    // {
    //     powofk[i] = powofk[i - 1] * k;
    // }
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }
    // cout << pq.top() << endl;
    if (k == 1){
        cout << pq.top() << endl;
        return;
    }
    int ans = 10000000000;
    int cnt = 1;
    int cnt_ = 0;
    while (1)
    {
        int top = pq.top();
        pq.pop();
        int tmp = ans;
        pq.push(top / k);
        ans = min(ans, min(top, pq.top()) + cnt);
        cnt++;
        if (ans >= tmp)
        {
            cnt_++;
        }
        if (cnt_ == n * 12)
        {
            break;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}