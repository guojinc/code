

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int mod = 1e9 + 7;
int cnt0, cnt1;

vector<int> fact0, inv_fact0, fact1, inv_fact1;

int mod_exp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void precompute_factorials0(int n, int mod) {
    fact0.resize(n + 1);
    inv_fact0.resize(n + 1);
    fact0[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact0[i] = fact0[i - 1] * i % mod;
    }
    inv_fact0[n] = mod_exp(fact0[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; --i) {
        inv_fact0[i] = inv_fact0[i + 1] * (i + 1) % mod;
    }
}

void precompute_factorials1(int n, int mod) {
    fact1.resize(n + 1);
    inv_fact1.resize(n + 1);
    fact1[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact1[i] = fact1[i - 1] * i % mod;
    }
    inv_fact1[n] = mod_exp(fact1[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; --i) {
        inv_fact1[i] = inv_fact1[i + 1] * (i + 1) % mod;
    }
}



int Combination0(int n, int k) {
    if (k > n || k < 0) return 0;
    return fact0[n] * inv_fact0[k] % mod * inv_fact0[n - k] % mod;
}

int Combination1(int n, int k)
{
     if (k > n || k < 0) return 0;
    return fact1[n] * inv_fact1[k] % mod * inv_fact1[n - k] % mod;
}

// void solve() {
//     int n, k;
//     cin >> n >> k;
//     cnt0 = cnt1 = 0;
//     precompute_factorials(n, mod);
//     for (int i = 0; i <= n; ++i) {
//         cout << "C(" << n << ", " << i << ") = " << Combination(n, i) << endl;
//     }
// }


void solve()
{
    int n, k;
    cin >> n >> k;
    cnt0 = cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num == 0) cnt0++;
        else cnt1++;
    }
    precompute_factorials0(cnt0, mod);
    precompute_factorials1(cnt1, mod);
    int ans = 0;

    if (cnt1 < (k + 1) / 2)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = min(k, cnt1); i >= (k + 1) / 2; i--)
    {
        ans = (ans + Combination1(cnt1, i) * Combination0(cnt0, k - i)) % mod;
    }

    cout << ans << endl;
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