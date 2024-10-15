#include <iostream>
#include <set>
using namespace std;

typedef long long ll;

int trees_range[60100];
// int trees_val[60100];
// int triv[30100][2];
set<int> s[60100];

set<int> unite(set<int> a, set<int> b)
{
    a.insert(b.begin(), b.end());
    return a;
}

void pushup_range(int i)
{
    trees_range[i] = trees_range[i * 2] + trees_range[i * 2 + 1];
}

// void pushup_val(int i)
// {
//     trees_val[i] = trees_val[i * 2] + trees_val[i * 2 + 1];
// }

// void build_range(int i, int l, int r)
// {
//     if (l == r)
//     {
//         trees_range[i] = triv[l][1];
//         return;
//     }

//     int mid = (l + r) / 2;

//     build_range(i * 2, l, mid);
//     build_range(i * 2 + 1, mid + 1, r);
//     pushup_range(i);
// }

// int query_range(int k, int i, int l, int r)
// {
//     if (l == r)
//     {
//         return l;
//     }

//     int mid = (l + r) / 2;

//     if (trees_range[i * 2] >= k)
//     {
//         return query_range(k, i * 2, l, mid);
//     }
//     else
//     {
//         return query_range(k - trees_range[i * 2], i * 2 + 1, mid + 1, r);
//     }
// }

set<int> query_val(int L,int R, int i, int l, int r)
{
    if (L <= l && r <= R)
    {
        return s[i];
    }

    int mid = (l + r) / 2;
    set<int> ans;
    if (L <= mid)
    {
        unite(ans, query_val(L, R, i * 2, l, mid));
    }
    if (R > mid)
    {
        unite(ans, query_val(L, R, i * 2 + 1, mid + 1, r));
    }
    return ans;
}

void build_val(int i, int l, int r)
{
    if (l == r)
    {
        // trees_val[i] = triv[l][0];
        int num;
        cin >> num;
        s[i].insert(num);
        return;
    }

    int mid = (l + r) / 2;

    build_val(i * 2, l, mid);
    build_val(i * 2 + 1, mid + 1, r);
    // pushup_val(i);
    s[i] = unite(s[i * 2], s[i * 2 + 1]);
}
int cal(set<int> s)
{
    int ans = 0;
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
         ans += *it;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int bef;
        // cin >> bef;
        // n--;
        // int len = 1;
        // triv[1][0] = bef;
        // triv[1][1] = 1;
        // while (n--)
        // {
        //     int num;
        //     cin >> num;
        //     if (num != bef)
        //     {
        //         len++;
        //         triv[len][0] = num;
        //         triv[len][1] = 1;
        //         bef = num;
        //     }
        //     else if (num == bef)
        //     {
        //         triv[len][1]++;
        //     }
        // }
        // for (int i = 0; i <= 2 * len + 1; i++)
        //     s[i].clear();
        // build_range(1, 1, len);
        build_val(1, 1, n);
        int q;
        cin >> q;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            // int L = query_range(l, 1, 1, len);
            // int R = query_range(r, 1, 1, len);
            cout << cal(query_val(l, r, 1, 1, n)) << endl;
        }
    }
}