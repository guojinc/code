#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
typedef pair<int, int> pii;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        map<char, int> mpc;
        map<int, char> mpi;
        string s;
        cin >> s;
        if (s.size() != n)
        {
            cout << "NO" << endl;
            continue;
        }
        for (int j = 0; j < s.size(); j++)
        {
            if (!mpc[s[j]])
            {
                if (!mpi[arr[j]])
                {
                    mpc[s[j]] = arr[j];
                    mpi[arr[j]] = s[j];
                }
                else
                {
                    cout << "NO" << endl;
                    break;
                }
            }
            else{
                if (mpi[arr[j]] != s[j])
                {
                    cout << "NO" << endl;
                    break;
                }
            }
            if (j == s.size() - 1)
                cout << "YES" << endl;
        }
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