#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int cha[30] = {0};
        long long ret = 0;
        char s[1000100];
        scanf("%s", s);
        int len = strlen(s);
        int size = 0;
        int k;
        cin >> k;
        int l = 0, r = 0;
        while (l < len)
        {
            while (size < k && r < len)
            {
                if (cha[s[r] - 'a'] == 0)
                {
                    size++;
                }
                cha[s[r] - 'a']++;
                r++;
            }
            if (size == k)
            {
                ret += len - r + 1;
            }
            cha[s[l] - 'a']--;
            if (cha[s[l] - 'a'] == 0)
            {
                size--;
            }
            l++;
        }
        printf("%lld\n", ret);
    }
    return 0;
}