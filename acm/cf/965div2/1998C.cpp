#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
typedef pair<int, int> pii;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool cmp(pii a, pii b)
{
    return a.first < b.first;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i].first = x;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i].second = x;
    }
    sort(arr.begin(), arr.end(), cmp);
    int Max = arr.back().first;
    int res1 = 0, res2 = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i].second == 1)
        {
            auto tmp = arr;
            tmp[i].first += k;
            sort(tmp.begin(), tmp.end(), cmp);
            // cout << tmp.back().first << " " << tmp[n / 2 - 1].first << endl;
            res1 = tmp.back().first + tmp[n / 2 - 1].first;
            break;
        }
    }
    if (res1 == 0)
    {
        res1 = arr.back().first + arr[n / 2 - 1].first;
    }
    int mid = arr[n / 2 - 1].first;
    priority_queue<int> pq;
    int cnt0 = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        if (arr[i].second == 1)
        {
            pq.push(arr[i].first);
        }
        if (arr[i].second == 0)
        {
            cnt0++;
        }
    }
    int cnt1 = 0;
    int sum = 0;
    int pos = n / 2 - 1;
    int P = pos;
    if (pq.empty())
    {
        cout << max(res1, res2) << endl;
        return;
    }
    int tmp = pq.top();
    pq.pop();
    while (cnt0 <= pos && sum < k && P < n - 1)
    {
        int incr = 0;
        while (arr[P].first == tmp)
        {
            P++;
            if (P == n)
            {
                break;
            }
            if (arr[P].second == 0)
            {
                cnt0++;
                incr++;
            }
            else
            {
                cnt1++;
            }
        }

        for (int i = 0; i < incr; i++)
        {
            if (pq.empty())
            {
                break;
            }
            int t = pq.top();
            pq.pop();
            sum += arr[P - 1].first - t;
            cnt1++;
        }
        if (cnt0 > pos || sum >= k)
        {
            if (sum == k)
                res2 = mid + arr.back().first;
            else res2 = mid + arr.back().first + 1;
            break;
        }
        if (P >= n)
        {
            break;
        }
        int t = arr[P].first;
        sum += (t - tmp) * cnt1;
        if (sum >= k)
        {
            res2 = mid + arr.back().first +  (k - (sum - (t - tmp) * cnt1)) / cnt1;
            break;
        }
        tmp = mid;
        mid = t;
    }
    if (res2 == 0)
    {
        res2 = mid + arr.back().first;
    }
    cout << max(res1, res2) << endl;
}   

signed main()
{
    ios
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}