#include <bits/stdc++.h>

using namespace std;

int kind[500500];
pair<int, int> range[3100];
int hold[3100];

int main()
{
    int n, k;
    while(scanf("%d %d", &n, &k) != EOF)
    {
        memset(hold, 0, sizeof(hold));
        for (int i = 0; i < n; i++)
        {
            cin >> kind[i];
        }    
        int cnt = 0;
        for (int i = 1; i <= k; i++)
        {
            int l, r;
            cin >> l >> r;
            range[i] = {l, r};
            if (l <= 0)
            {
                cnt++;
            }
        }
        if (cnt == k)
        {
            cout << 0 << endl;
            continue;
        }

        int l = 0, r = 0;
        int cnt_out = 0;
        int cnt_in = cnt;
        int ans = 10000000;
        while (l < n)
        {
            while (r < n && cnt_in < k)
            {
                hold[kind[r]]++;
                if (hold[kind[r]] == range[kind[r]].first)
                {
                    cnt_in++;
                }
                if (hold[kind[r]] == range[kind[r]].second + 1)  
                {
                    cnt_out++;
                }
                r++;
            }
            if (cnt_in == k && cnt_out == 0)
            {
                ans = min(ans, r - l);
            }
            if (hold[kind[l]] == range[kind[l]].first)
            {
                cnt_in--;
            }
            if (hold[kind[l]] == range[kind[l]].second + 1)
            {
                cnt_out--;
            }
            hold[kind[l]]--;
            l++;
        }
        cout << ((ans == 10000000) ? -1 : ans) << endl;
    }
}