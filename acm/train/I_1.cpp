#include <iostream>
#include <vector>
using namespace std;

int max(int x, int y)
{
    return x > y ? x : y;
}
int ans = 1;
int t, n;
void dfs(int cur, int r, vector<int>& to)
{
    if (r == t)
    {
        cout << ans << endl;
        return;
    }
    int ter = r;
    for (int i = cur; i <= r; i++)
    {
        ter = max(ter, to[i]);
    }
    if (ter == r && to[r + 1] == 0)
    {
        cout << -1 << endl;
        return;
    }
    else if (ter == r + 1 && to[r + 1] != 0)
    {
        ans++;
        dfs(r + 1, to[r + 1], to);
        return;
    }
    else if (ter == r && to[r + 1] != 0)
    {
        ans++;
        dfs(r + 1, to[r + 1], to);
        return;
    }
    ans++;
    dfs(r + 1, ter, to);
}

int main()
{
    cin >> n >> t;
    vector<int> to(t + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        to[l] = max(to[l], r);
    }
    dfs(1, to[1], to);
    to.clear();
}
