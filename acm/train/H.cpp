#include <queue>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

struct dsu{
    vector<int> p;
    dsu(int n) : p(n) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void unite(int x, int y) { p[find(x)] = find(y); }
    ~dsu() { p.clear(); }
};

struct Pair{
    int k, v;
    bool operator < (const Pair &p) const { return v < p.v; }
};

void combine(priority_queue<Pair> &a, priority_queue<Pair> &b){
    int A_k = a.top().k;
    int B_k = b.top().k;
    int A = a.top().v;
    int B = b.top().v;
    A /= 2;
    B /= 2;
    a.pop();
    b.pop();
    a.push({A_k, A});
    b.push({B_k, B});
    while(!b.empty()){
        a.push(b.top());
        b.pop();
    }
    
}
vector<priority_queue<Pair>> root;
int main()
{
    int n;
    cin >> n;
    dsu d(n);
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        priority_queue<Pair> pq;
        pq.push({i, v});
        root.push_back(pq);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (d.find(x) == d.find(y)){
            cout << -1 << endl;
            continue;
        }
        combine(root[d.find(y)], root[d.find(x)]);
        d.unite(x, y);
        cout << root[d.find(y)].top().v << endl;
    }
    d.~dsu();
}
