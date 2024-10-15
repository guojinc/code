#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> res;
        int cnts_a = 0;
        for (auto c : s)
        {
            if (c == '1')
            {
                cnts_a++;
            }
        }
        for (int i = 0; i <= k; i++)
        {
            int numt = (cnts_a + i) % (int)pow(2, k);
            int num = numt;
            int cnt_num = 0;
            while (1)
            {
                if (num == 0)
                {
                    break;
                }
                if (num & 1)
                    cnt_num++;
                num >>= 1;
            }
            if (cnt_num == i)
            {
                res.push_back(numt);
            }
        }
        sort(res.begin(), res.end());
        if (res.size() == 0)
        {
            cout << "None" << endl;
            continue;
        }
        int r = res[0];
        string ans;
        for (int i = 0; i < k; i++)
        {
            if (r & 1)
            {
                ans += '1';
            }
            else
            {
                ans += '0';
            }
            r >>= 1;
        }
        for (int i = k - 1; i >= 0; i--)
        {
            cout << ans[i];
        }
        cout << endl;
    }
    
}