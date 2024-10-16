#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
typedef pair<int, int> pii;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Point
{
    int x, y;
};

int dist(Point a, Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void solve()
{
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    Point start;
    Point end;
    cin >> start.x >> start.y >> end.x >> end.y;
    int Min = dist(start, end);
    for (int i = 0; i < n; i++)
    {
        if (dist(end, p[i]) <= Min)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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