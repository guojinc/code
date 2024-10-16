#include <iostream>
#include <vector>
#include <ios>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
#define int long long
#define mod 998244353

int a[40];



void solve()
{
    int n, k;
    cin >> n >> k;
    if (n <= k)
    {
        cout << "Alice" << endl;
        return;
    }
    if (n % 2)
    {
        cout << "Alice" << endl;
        return;
    }
    if (k == 1)
    {
        cout << "Bob" << endl;
        return;
    }
    if (n / 2 % 2 == 1)
    {
        cout << "Alice" << endl;
        return;
    }
   int t=1,num=0;
   while(a[t]<=k){
        if(n/a[t]%2==1){
            cout<<"Alice"<<endl;
            return ;
        }
        t++;
   }
   cout<<"Bob"<<endl;
    

    // if ((k << 1) >= n || ((k << 1) & n) != 0)
    // {
    //     cout << "Alice" << endl;
    // }
    // else{
    //     cout << "Bob" << endl;
    // }
}

signed main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    a[0]=1;
    for(int i=1;i<=40;i++)a[i]=a[i-1]*2;
    while (t--)
    {
        solve();
    }

}