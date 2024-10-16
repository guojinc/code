#include <iostream>
#define int long long
using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        // if (n == 1)
        // {
        //     int a;
        //     string b;
        //     cin >> a >> b;
        //     int c;
        //     if (b[0] == 'A')
        //     {
        //         cout << "Yes" << endl;
        //         continue;
        //     }
        //     else{
        //         c = b[0] - '0';
        //     }
        //     ans += a * c;
        //     if (ans == 0)
        //     {
        //         cout << "No" << endl;
        //         continue;
        //     } 
        //     if (ans % 5 == 0)
        //     {
        //         cout << "Yes" << endl;
        //     }
        //     else{
        //         cout << "No" << endl;
        //     }
        //     continue;
        // }
        while (n--)
        {
            int a;
            string b;
            cin >> a >> b;
            int c;
            if (b[0] == 'A')
            {
                c = 0;
            }
            else{
                c = b[0] - '0';
            }
            ans += a * c;
            ans %= 5;
        }
        if (ans % 5 == 0)
        {
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}