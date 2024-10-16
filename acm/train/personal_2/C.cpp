#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
struct Node
{
    int pa;
    int child;
    int depth;
};

long long multi(vector<int> nodes)
{
    long long ans = 1;
    for (int i = 0; i < nodes.size(); i++)
    {
        ans = ans * nodes[i] % mod;
    }
    return ans;
}

long long helper(vector<int> nodes, int index, int k, vector<int> mul)
{
    if (k == 0)
    {
        return multi(mul);
    }
    if (index == nodes.size())
    {
        return 0;
    }
    else
    {
        long long ans = 0;
        ans += helper(nodes, index + 1, k, mul);
        mul.push_back(nodes[index]);
        ans += helper(nodes, index + 1, k - 1, mul);
        return ans % mod;
    }
}

long long cal(map<int, int> depth_nodes)
{
    vector<int> nodes;
    for (auto i : depth_nodes)
    {
        nodes.push_back(i.second);
    }
    long long ret = 0;
    for (int i = 2; i <= nodes.size(); i++)
    {
        ret = (ret + helper(nodes, 0, i, {})) % mod;
    }
    return ret;
}

int cmp(Node a, Node b)
{
    return a.depth > b.depth;
}

long long pow_mod(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int l = n;
    vector<Node> nodes(n + 1,{0,0,0});

    nodes[0] = {-1, -1, -1};
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        nodes[b].pa = a;
        nodes[b].depth = nodes[a].depth + 1;
        nodes[a].child++;
        if (n == 1) break;
    }
    
    sort(nodes.begin(), nodes.end(), cmp);
    int depth = nodes[0].depth;


    map<int, int> depth_nodes;
    map<int, int> depth_lnodes;
    for (int i = 0; i < l; i++)
    {
        if (nodes[i].depth == depth)
        {
            depth_nodes[nodes[i].pa]++;
        }
        else if (nodes[i].depth == depth - 1 && nodes[i].child == 0)
        {
            depth_lnodes[nodes[i].pa]++;
        }
    }
    long long ans = 1;
    if (depth_nodes.size() == 1 && depth_lnodes.size() != 0)
    {
        auto it = depth_nodes.begin();
        long long cnt = 0;
        for (auto i : depth_lnodes)
        {
            cnt += i.second;
        }
        cout << (cnt * it->second) % mod << endl;
    }
    else if (depth_nodes.size() > 1)
    {
        ans = cal(depth_nodes);
        cout << ans % mod << endl;
    }
    else if (depth_nodes.size() == 1 && depth_lnodes.size() == 0)
    {
        auto it = depth_nodes.begin();
        if (it->second == 1)
        {
            cout << 1 << endl;
            return 0;
        }
        cout << pow_mod(2, it->second) - it->second - 1 << endl;
    }
}