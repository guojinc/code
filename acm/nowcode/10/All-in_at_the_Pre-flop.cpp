#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define pii pair<int, int>
#define umap unordered_map
#define uset unordered_set
#define mod 998244353
#define mod7 1e9 + 7
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

long long extend_gcd(long long a,long long b,long long &x,long long &y){
    if(a==0&&b==0) return -1;//无最大公约数
    if(b==0){x=1;y=0;return a;}
    long long d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
 //********* 求逆元 *******************
 //ax = 1(mod n)
 long long mod_reverse(long long a,long long n){
    long long x,y;
    long long d=extend_gcd(a,n,x,y);
    if(d==1) return (x%n+n)%n;
    else return -1;
 }

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a < b)
    {
        int cnt = 1;
        while (a < b)
        {
            b -= a;
            a *= 2;
            cnt++;
        }
        int m = mod_reverse(1 << cnt, mod);
        cout << m << " " << mod - m + 1 << endl;
    }
    else if (a == b)
    {
        cout << mod_reverse(2, mod) << " " << mod_reverse(2, mod) << endl;
    }
    else
    {
        int cnt = 1;
        while (a > b)
        {
            a -= b;
            b *= 2;
            cnt++;
        }
        int m = mod_reverse(1 << cnt, mod);
        cout << mod - m + 1 << " " << m << endl;
    }
    // int m = mod_reverse(, mod);
    // cout << m << " " << mod - m + 1 << endl;

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