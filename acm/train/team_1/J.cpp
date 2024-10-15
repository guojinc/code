#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    map<string, int> mp;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        for (int i = 0; i < 14; i++)
        {
            string t;
            t = s.substr(i * 2, 2);
            mp[t]++;
        }
        if (mp.size() == 13)
        {
            bool flag = true;
            for (auto i : mp)
            {
                if (i.first == "1s" || i.first == "9s" || i.first == "1m" || i.first == "9m" || i.first == "1p" || i.first == "9p" || i.first == "1z" || i.first == "2z" || i.first == "3z" || i.first == "4z" || i.first == "5z" || i.first == "6z" || i.first == "7z")
                {
                    continue;
                }
                else{
                    flag = false;
                    cout << "Otherwise" << endl;
                    break;
                }
            }
            if (flag)
            {
                cout << "Thirteen Orphans" << endl;
            }
        }
        else if (mp.size() == 7)
        {
            bool flag = true;
            for (auto i : mp)
            {
                if (i.second == 2)
                {
                    continue;
                }
                else{
                    flag = false;
                    cout << "Otherwise" << endl;
                    break;
                }
            }
            if (flag)
            {
                cout << "7 Pairs" << endl;
            }
        }
        else{
            cout << "Otherwise" << endl;
        }
        mp.clear();
    }
}