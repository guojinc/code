#include <iostream>
#include <vector>
#include <ios>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
#define int long long
#define mod 998244353

int Factor[1005];

int factor(int n)
{
    Factor[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        Factor[i] = Factor[i - 1] * i % mod; 
    }
}

void solve()
{
    map<int, int> arr; 
    int n;
    cin >> n;
    factor(n);
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        arr[nums[i]]++;
    }
    sort(nums.begin(), nums.end());
    int ans = 0;
    int res = 1;
    if (arr.size() == 1)
    {
        res = 1;
    }
    else{
        res = 2;
    }
    for (auto i : nums)
    {
        res *= Factor[arr[i]];
        res %= mod;
        arr[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans += nums[j] - nums[i];
        }
    }

    cout << ans << " " << res << endl;
}

signed main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

}