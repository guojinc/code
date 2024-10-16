#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long l = n;
    long long ans = 0;
    while (n--)
    {
        long long num;
        cin >> num;
        ans += num;
    }
    long long m = ans % l;
    long long k = ans / l;
    if (m == 0)
    {
        cout << k << endl;
    }
    else
    {
        int arr[32];
        arr[0] = 1;
        for (int i = 1; i < 32; i++)
        {
            arr[i] = arr[i - 1] * 2;
        }
        int a1 = 0;
        int a2 = 0;
        for (int i = 30; i >= 0; i--)
        {
            if (arr[i] * l > ans)
            {
                if ((arr[i] - 1) * l < ans)
                {
                    a1 += arr[i];
                    int cnt = min(l, ans / arr[i]);
                    ans -= arr[i] * cnt;
                }   
            }
            if (arr[i] * l <= ans)
            {
                a1 += arr[i];
                ans -= l * arr[i];
            }
        }
        cout << a1 << endl;
    }
}