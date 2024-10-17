#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

signed main()
{
    ios
    int la, lt;
    cin >> la >> lt;
    list<char> s, t;
    string T;
    for (int i = 0; i < la; i++)
    {
        char c;
        cin >> c;
        s.push_back(c);
    }
    for (int i = 0; i < lt; i++)
    {
        char c;
        cin >> c;
        t.push_back(c);
        T += c;
    }
    auto tmp = t;
    int flag = 0;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (tmp.size() == 0)
        {
            break;
        }
        if (*it == tmp.front())
        {
            tmp.pop_front();
        }
        else{
            auto it2 = it;
            it2--;
            s.erase(it);
            it = it2;
            flag = 1;
        }
    }
    tmp = t;
    for (auto it = s.rbegin(); it != s.rend(); it++)
    {
        if (tmp.size() == 0)
        {
            break;
        }
        if (*it == tmp.front())
        {
            tmp.pop_front();
        }
        else{
            auto it2 = it;
            it2--;
            s.erase(it.base());
            it = it2;
            flag = 1;
        }
    }
    T += T[0];
    string Tt = T;
    reverse(T.begin(), T.end());
    if (T != Tt)
    {   
        if (s.size() >= lt * 2)
        {
            int len = s.size() - (lt * 2);
            cout << len * (len + 1) / 2 << endl;
        }
    }
    else{
        int ans = 0;
        if (s.size() >= lt * 2 - 1)
        {
            int len = s.size() - (lt * 2 - 1);
            ans += len * (len + 1) / 2;
        }
        ans += (s.size() - lt - 1) / lt;
        cout << ans << endl;
    }
    
}