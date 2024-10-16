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

vector<int> eulerSieve(int n) {
    vector<int> primes;
    vector<bool> is_prime(n + 1, true);
    
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    return primes;
}

vector<int> primes = eulerSieve(30000);
int powerof2[31];

void solve()
{
    int n;
    cin >> n;
    double MAX = 0;
    int k = 0;
    // for (int k = 1; k <= 30000; k++)
    // {
        start:
        // int n = k;
        // int k = 0;
        vector<int> num; 
        int i = 1 + k;
        double ans = 0;
        while (1)
        {
            if (n >= primes[i])
            {
                num.push_back(primes[i]);
                n -= primes[i];
                i++;
            }
            else{
                for (int j = 0; j < 31; j++)
                {
                    if (n >= powerof2[j] && n < powerof2[j + 1] || n == 0)
                    {
                        num.push_back(powerof2[j]);
                        n -= powerof2[j];
                        for (int k = 0; k < num.size(); k++)
                        {
                            ans += log(num[k]);
                        }
                        // printf("%.9f\n", ans);
                        // printf("%.9f\n", exp(ans));
                        MAX = max(MAX, ans);
                        k++;
                        if (primes[k - 1] > n)
                        {
                            printf("%.9f\n", MAX);
                            return;
                        }
                        goto start;
                        return;
                    }
                }
            }
        }   
    // }
}

signed main()
{
    ios
    int t = 1;
    cin >> t;
    powerof2[0] = 1;
    for (int i = 1; i < 31; i++)
    {
        powerof2[i] = powerof2[i - 1] * 2;
    }
    while (t--)
    {
        solve();
    }
}