/*poj1392Ouroboros_Snake*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int path[2<<16],h,n,k,vis[2<<16],ans[2<<16];
void dfs(int x)
{
    int t1=(x<<1)&((1<<n)-1),t2=t1+1;//t1为x去掉最高位，末尾加0；t2为x去掉最高位，末尾加1；
    if(!vis[t1])//注意2个if的先后顺序。
    {
        vis[t1]=1;
        dfs(t1);
        path[h++]=0;//记录字典序最小的01序列，
    }
    if(!vis[t2])
    {
        vis[t2]=1;
        dfs(t2);
        path[h++]=1;
    }
}
int main()
{
    int i,j,sum;
    while(~scanf("%d %d",&n,&k))
    {
        if(n==0&&k==0)break;
        h=0;
      for(i=0;i<n-1;i++)//进行初始化
        path[h++]=0,ans[i]=0;
        memset(vis,0,sizeof(vis));
      dfs(0);
      j=n-1;
      for(i=h-1;i>=n-1;i--)//注意倒序一下。
        ans[j++]=path[i];
      sum=0;
      for(i=k;i<k+n;i++)
        sum=sum*2+ans[i];
        cout<<sum<<endl;
    }
    return 0;
}
