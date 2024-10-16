#include <iostream>
#include <cmath>
#include <string>

using namespace std;


int Query(int a[],int sums[], int l, int r, int n)
{
    int sum = 0;
    int m = sqrt(n);

    int l_block = l / m + (l % m ? 1 : 0);
    int r_block = (r + 1) / m;

    int l_remain = (m - l % m == m) ? 0 : m - l % m;
    int r_remain = (r + 1) % m;

    for (int i = l_block; i < r_block; i++)
    {
        sum += sums[i];
    }
    for (int i = l; i < l + l_remain; i++)
    {
        sum += a[i];
    }
    for (int i = r - r_remain + 1; i <= r; i++)
    {
        sum += a[i];
    }
    return sum;
}

void Add(int a[], int sums[], int l, int r, int n)
{
    a[l] += r;
    int m = sqrt(n);
    sums[l / m] += r;
}

void Sub(int a[], int sums[], int l, int r, int n)
{
    a[l] -= r;
    int m = sqrt(n);
    sums[l / m] -= r;
}

int main()
{
    int t;
    cin >> t;
    int k = t;
    while (t--)
    {
        int n;
        int i = 0;
        cin >> n;
        int a[50010];
        while (i < n)
        {
            cin >> a[i++];   
        }

        int m = sqrt(n);
        int block = n / m + (n % m ? 1 : 0);
        int sums[250] = {0};
        for (int i = 0; i < n; i++)
        {
            sums[i / m] += a[i];
        }

        string s;
        cout << "Case " << k - t << ":\n";
        while (1)
        {
            cin >> s;
            if (s == "End")
            {
                break;
            }
            if (s == "Query")
            {
                int l, r;
                cin >> l >> r;
                cout << Query(a, sums, l - 1, r - 1, n) << "\n";
            }
            else if (s == "Add")
            {
                int l, r;
                cin >> l >> r;
                Add(a,sums, l - 1, r, n);
            }
            else if (s == "Sub")
            {
                int l, r;
                cin >> l >> r;
                Sub(a,sums, l - 1, r, n);
            }
            
        }
    }
}