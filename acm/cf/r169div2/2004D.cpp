#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define pii pair<int, int>
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(),a.end()
#define bg begin()
#define ed end()
#define mod 998244353
#define mod7 1e9 + 7
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string cmp(string cmp);

void check(int L, int R, vector<string>& arr,const umap<string, vector<int>>& mp)
{
    const string& l = arr[L];
    const string& r = arr[R];
    if (l[0] == r[0] || l[1] == r[0] || l[1] == r[1] || l[0] == r[1])
    {
        cout << abs(R - L) << endl;
        return;
    }
    if (L > R)
    {
        swap(L, R);
    }
    string find1 = cmp(string(1, l[0]) + r[0]);
    string find2 = cmp(string(1, l[0]) + r[1]);
    string find3 = cmp(string(1, l[1]) + r[0]);
    string find4 = cmp(string(1, l[1]) + r[1]);
    vector <string> f = {find1, find2, find3, find4};

    int Min = 1000000000;
    for (int i = 0; i < 4; i++)
    {
        const string& tmp = f[i];
        if (mp.find(f[i]) == mp.end()) continue;
        const vector<int>& t = mp.at(f[i]);
        if (t.size())
        {
            if (t.back() < L) Min = min(Min, L - t.back());
            else if (t[0] > R) Min = min(Min, t[0] - R);
            else{
                auto lf = lower_bound(all(t), L);
                if (lf != t.ed)
                {
                    if (*lf < R){
                        cout << R - L << endl;
                        return;
                    }
                }
                lf--;
                auto rt = lower_bound(all(t), R);
                Min = min({Min, L - *lf, *rt - R});
            }
        } 
    }
    if (Min == 1000000000)
    {
        cout << -1 << endl;
        return;
    }
    cout << Min * 2 + R - L << endl;
}

string cmp(string s)
{
    if (s[0] > s[1])
    {
        return ""s + s[1] + s[0];
    }
    return s;
}


void solve()
{
    int n, q;
    cin >> n >> q;
    umap<string, vector<int>> mp;
    vector<string> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        arr[i] = cmp(s);
        mp[arr[i]].emplace_back(i);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        check(l, r, arr, mp);
    }
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