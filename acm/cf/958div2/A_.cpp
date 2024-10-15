#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
      int t, k;
      cin >> t >> k;
      if (t == 1)
      {
        cout << 0 << endl;
        continue;
      }
      int cnt = 0;
      while (t > k)
      {
          t = t - k + 1;
          cnt++;
      }
      cnt++;
      cout << cnt << endl;
    }
}