#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
typedef pair<int, int> pii;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Node
{
    int x;
    int depth;
};

int powof2[30];
void gener(vector<int> &permu, int n, int id, int depth)
{
    if (powof2[depth] - 1 == n)
    {
        permu[id] = depth;
        return;
    }
    permu[id] = depth;
    gener(permu, n, id + 1, depth + 1);
    gener(permu, n, id + n / powof2[depth] + 1, depth + 1);
}

void swap(Node &a, Node &b)
{
    Node temp = a;
    a = b;
    b = temp;
}

void query(vector<int> &permu, vector<int> &nodes, set<Node> &y, set<Node> &n)
{
    int a, b;
    cin >> a >> b;
    swap(nodes[a], nodes[b]);
    if (nodes[a].depth == nodes[b].depth)
    {
        if (n.size() == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
            
        }
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
    }
    vector<Node> nodes(n + 1);
    vector<int> permu(n + 1);
    gener(permu, n, 1, 1);
    // for (int i = 1; i <= n; i++)
    // {
    //     cerr << permu[i] << " ";
    // }
    set<Node> y, n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nodes[i].x;
        nodes[i].depth = nodes[i].x / 2 + 1;
        if (nodes[i].depth == permu[i])
        {
            y.insert(nodes[i]);
        }
        else
        {
            n.insert(nodes[i]);
        }
    }

    while (q--)
    {
        query(permu, nodes, y, n);
    }
}

signed main()
{
    ios
    int t = 1;
    cin >> t;
    powof2[0] = 1;
    powof2[1] = 2;
    for (int i = 2; i < 30; i++)
    {
        powof2[i] = powof2[i - 1] * 2;
    }
    while (t--)
    {
        solve();
    }
}