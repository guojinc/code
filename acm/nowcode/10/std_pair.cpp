#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
typedef pair<int, int> pii;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

list<string> split(string s, vector<char> del)
{
    list<string> res;
    string temp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (find(del.begin(), del.end(), s[i]) == del.end())
        {
            temp += s[i];
        }
        else
        {
            if (temp != "")
            {
                res.push_back(temp);
                temp = "";
            }
        }
    }
    if (temp != "")
    {
        res.push_back(temp);
    }
    return res;
}

struct Node
{
    string name;
    struct Node* left;
    struct Node* right;
};

Node* build(list<string>& v)
{
    Node* node = new Node();
    node->name = v.front();
    v.pop_front();
    if (node->name == "pair")
    {
        node->left = build(v);
        node->right = build(v);
    }
    else
    {
        node->left = NULL;
        node->right = NULL;   
    }
    return node;
}

void print(Node* node)
{
    if (node->name == "pair")
    {
        cout << "pair<";
        print(node->left);
        cout << ",";
        print(node->right);
        cout << ">";
    }
    else
    {
        cout << node->name;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    map<string, Node*> mp;
    string S;
    getline(cin, S);
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        list<string> v = split(s, {'<','>',' ',';',','});
        string name = v.back();
        v.pop_back();
        mp[name] = build(v);
        // cout << v.size() << endl;
        // for (int i = 0; i < v.size(); i++)
        // {
        //     cout << v[i] << " ";
        // }
        // cout << endl;
    }

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        list<string> v = split(s, {'.'});
        Node* node = mp[v.front()];
        while (v.size() > 1)
        {
            v.pop_front();
            if (v.front() == "first")
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        print(node);
        cout << endl;
    }
}

signed main()
{
    ios
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}