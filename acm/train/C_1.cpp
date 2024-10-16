#include <iostream>

using namespace std;

int arr[100010];

int main()
{
    int t;
    int cas = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans = 0;
        int OR = 0;
        for (int i = 0; i < n; i++)
        {
            int l = i;
            while (OR < m && i < n)
            {
                OR |= arr[i++];
                if (OR < m)
                    ans++;
            }
            i = l;
            OR = 0;
            

        }
        cout << "Case #" << cas++ << ": " << ans << endl;
    }

}