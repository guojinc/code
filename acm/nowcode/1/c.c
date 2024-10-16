#include <stdio.h>
const long long mod = 1000000007;
long long  a[1000000];
int main()
{
    long long n;
    scanf("%lld", &n);
    long long end = 0;
    while (n--)
    {
        long long t, v;
        scanf("%lld %lld", &t, &v);
        end -= t;
        end++;
        a[end] = v;
        long long ans = 0;
        long long sum = 0;
        for (long long i = end; i > 0; i--)
        {
            sum = (sum + a[i]) % mod;
            ans = (ans + sum) % mod;
        }
        printf("%lld\n",ans);
    }
}