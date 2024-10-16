#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int sum[12345678];
void PushUp(int node)//更新最大值
{
  sum[node] = max(sum[node*2], sum[node*2+1]);
}
void Build(int l, int r, int node)//建树
{
   if(l==r)
   {
     scanf("%d", &sum[node]);
     return ;
   }
   int m = (l + r) / 2;
   Build(l, m, node * 2);
   Build(m+1, r, node * 2 + 1);
   PushUp(node);//更新
}
void UpData(int p, int add, int l, int r, int node)//更新节点
{
  if(l==r)
  {
    sum[node] = add;
    return ;
  }
  int m = (l + r) / 2;
  if(p<=m)
  UpData(p, add, l, m, node * 2);
  else
  UpData(p, add, m+1, r, node * 2 + 1);
  PushUp(node);
}
int Query(int L, int R, int l, int r, int node)//求最大值
{
    if(L<=l&&r<=R)
    {
       return sum[node];
    }
    int m = (l + r) / 2;
    int ans1 = 0, ans2 = 0;
    if(L<=m)
    ans1 = Query(L, R, l, m, node * 2);
    if(R>m)
    ans2 = Query(L, R, m+1, r, node * 2 + 1);
    return max(ans1, ans2);
}
int main()
{
   int n, a, b, m;
   while(~scanf("%d %d", &n, &m))
   {
      Build(1, n, 1);
      char op;
      getchar();//注意
      while(m--)
      {
        scanf("%c", &op);
        scanf("%d %d", &a, &b);
        if(op=='Q')
        printf("%d\n", Query(a, b, 1, n, 1));
        else if(op=='U')
        UpData(a, b, 1, n, 1);
        getchar();//注意
      }
   }
  return 0;
}
