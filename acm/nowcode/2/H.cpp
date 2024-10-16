#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    int ans = 0;
    int l, r;
    l = r = 0;
    int nx, ny;
    nx = ny = 0;
    int record = -1;
    int recordx = 0;
    int recordy = 0;
    for (l = 0; l < n; l++)
    {
        r = record;
        record = -1;
        nx = recordx;
        ny = recordy;
        if (r == -1)
        {
            r = l;
            nx = ny = 0;
            recordx = recordy = 0;
        }
        while ((nx != x || ny != y) && r < n)
        {
            if (s[r] == 'A')
            {
                nx--;
            }
            else if (s[r] == 'S')
            {
                ny--;
            }
            else if (s[r] == 'D')
            {
                nx++;
            }
            else if (s[r] == 'W')
            {
                ny++;
            }
            if ((nx == x || ny == y) && record == -1)
            {
                record = r;
                recordx = nx;
                recordy = ny;
            }
            if (nx == x && ny == y)
            {
                break;
            }
            r++;
        }
        ans += n - r;
        if (s[l] == 'A')
        {
            nx++;
            recordx++;
        }
        else if (s[l] == 'S')
        {
            ny++;
            recordy++;
        }
        else if (s[l] == 'D')
        {
            nx--;
            recordx--;
        }
        else if (s[l] == 'W')
        {
            ny--;
            recordy--;
        }
    }
    cout << ans << endl;
}