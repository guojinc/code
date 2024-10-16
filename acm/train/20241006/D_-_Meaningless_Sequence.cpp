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
#define mod7 1000000007
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int powerofc[3005];

struct Comb{
    int a[3005];
    Comb(){
        memset(a,0,sizeof(a));
    }
    Comb operator+(const Comb &b){
        Comb c;
        for(int i=0;i<3005;i++){
            c.a[i] = (a[i] + b.a[i]) % mod7;
            if (a[i] == 0 && b.a[i] == 0)
            {
                break;
            }
        }
        return c;
    }
    Comb operator>>(int x){
        Comb c;
        for(int i=1;i<3005;i++){
            c.a[i] = a[i - 1]; 
            if (a[i - 1] == 0)
            {
                break;
            }
        }
        return c;
    }
    bool operator==(const Comb &b){
        for(int i=0;i<3005;i++){
            if(a[i] != b.a[i]){
                return false;
            }
        }
        return true;
    }
};

Comb dp[3005];
void solve()
{
    string s;
    int c;
    int ans = 1;
    cin >> s >> c;
    int len = s.length();
    int id = 1;
    dp[0] = Comb();
    vector<Comb> Combs(3005, Comb());
    for (int i = 0; i <= len; i++)
    {
        Combs[i].a[0] = 1;
        for (int j = 1; j <= i; j++)
        {
            Combs[i].a[j] = (Combs[i - 1].a[j] + Combs[i - 1].a[j - 1]) % mod7;
        }
    }

    powerofc[0] = 1;
    for (int i = 1; i <= len; i++)
    {
        powerofc[i] = (powerofc[i - 1] * c) % mod7;
    }
    reverse(s.begin(), s.end());
    for (auto it : s)
    {
        if (it == '0')
        {
            dp[id] = dp[id - 1];
        }
        else
        {
            if (dp[id - 1] == dp[0])
            {
                dp[id].a[1] = 1;
            }
            else{
                dp[id] = dp[id - 1] >> 1;
            }
            dp[id] = dp[id] + Combs[id - 1];
        }
        id++;
    }
    Comb f = dp[len];
    for (int i = 1; i <= len; i++)
    {
        ans = (ans + f.a[i] * powerofc[i]) % mod7;
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