#include<stdio.h>
#include<string.h>
int val[107];
double dis[107],map[107][107];
int n,m;
double count=0;
 
void init()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            map[i][j]=-1;
}
 
void dijstra()
{
    int vis[107];
    int i,j;
	double max;
	int flag=n;
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    vis[flag]=1;
    dis[flag]=1.0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        if(map[j][flag]!=-1&&!vis[j]&&dis[j]<dis[flag]*map[j][flag])
        {
            dis[j]=dis[flag]*map[j][flag];
        }
        max=0;
        for(j=1;j<=n;j++)
        if(!vis[j]&&dis[j]>max)
        {
            max=dis[j];
            flag=j;
        }
        vis[flag]=1;
    }
    for(i=1;i<n;i++)
    count+=dis[i]*val[i];
}
 
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        count=0;
        int i,j;
        init();
        for(i=1;i<n;i++)
        scanf("%d",&val[i]);
        int from,to;
        double rate;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%lf",&from,&to,&rate);
            if(map[from][to]<(1.0-rate))
            map[from][to]=map[to][from]=(1.0-rate);
        }
        dijstra();
        printf("%.2f\n",count);
    }
    return 0;
}