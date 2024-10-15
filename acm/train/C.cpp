#include <iostream>

using namespace std;

int arr[100010];

long long cal(int n)
{
    return n * (n + 1) / 2;
}

int main()
{
    int t, cas = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int l = 0, r = 0;
        long long ans = 0;
        while (l < n)
        {
            int OR = 0;
            while (OR < m && r < n)
            {
                OR |= arr[r];
                r++;
            }
            if (r == n && arr[r - 1] >= m)
            {
                ans += cal(r - l - 1);
                break;
            }
            if (r == n && OR < m)
            {
                ans += cal(r - l);
                break;
            }
            if (arr[r - 1] >= m)
            {
                ans += cal(r - l - 1);
                l = r;
                continue;
            }

            ans += cal(r - l - 1);
            int temp = l;
            l = r - 1;
            OR = 0;
            while (OR < m && l >= temp)
            {
                OR |= arr[l];
                l--;
            }
            ans += cal(r - l - 3);
            r--;
            l += 2;
            
            
        }
        cout << "Case #" << cas++ << ": " << ans << endl;
    }
}