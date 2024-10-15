#include <bits/stdc++.h>
using namespace std;

int arr[100500];

int main()
{
    int n ,s;
    cin >> n >> s;
    long long cal = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cal += arr[i];
    }
    if (cal == s)
    {
        cout << n << endl;
    }
    else{
        cout << n - 1 << endl;
    }
    return 0;
    sort(arr, arr + n);
    int i = 0;
    if (cal < s)
    {
        while (cal < s)
        {   
            cal = cal - arr[i] + 10000;
            i++;
        }
        cout << n - i << endl;
        return 0;
    }
    if (cal > s)
    {
        while (cal > s)
        {
            cal = cal - arr[n - i - 1] - 10000;
            i++;
        }
        cout << n - i << endl;
    } 
}