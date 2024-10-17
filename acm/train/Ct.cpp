#include<algorithm>
#include<iostream>
#include<string.h>
#include<sstream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=100010;
int bit[35],abit[35];
int a[maxn];
int main()
{
    int i,j,k,n,m,sum,pre,t,cas=1;
    __int64 ans;
    bit[0]=1;
    for(i=1;i<=31;i++)//预处理出二进制数组
        bit[i]=bit[i-1]<<1;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        memset(abit,0,sizeof abit);//记录各二进制位1的个数
        scanf("%d%d",&n,&m);
        ans=(__int64)n*(n+1)/2;//用排除法。所以先算出总组合数。(n*(n-1))/2 + n。
        for(i=0;i<n;i++)
            scanf("%d",a+i);
        i=j=0;//i,j指针扫一遍
        while(j<n)
        {
            while(sum<m&&j<n)//如果小于m。可以向右扩展。
            {
                sum|=a[j];
                for(k=0;k<31;k++)
                    if(a[j]&bit[k])
                        abit[k]++;
                j++;
            }
            pre=i;
            while(sum>=m)
            {
                for(k=0;k<31;k++)
                    if(a[i]&bit[k])
                        abit[k]--;
                sum=0;
                for(k=0;k<31;k++)
                    if(abit[k])
                        sum|=bit[k];
                i++;
            }
            ans-=(i-pre)*(n-j+1);//(i-pre)的部分和(n-j+1)的部分肯定不能组合。
        }
        printf("Case #%d: %I64d\n",cas++,ans);
    }
    return 0;
}