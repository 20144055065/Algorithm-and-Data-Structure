/*poj1392Ouroboros_Snake*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int path[2<<16],h,n,k,vis[2<<16],ans[2<<16];
void dfs(int x)
{
    int t1=(x<<1)&((1<<n)-1),t2=t1+1;//t1Ϊxȥ�����λ��ĩβ��0��t2Ϊxȥ�����λ��ĩβ��1��
    if(!vis[t1])//ע��2��if���Ⱥ�˳��
    {
        vis[t1]=1;
        dfs(t1);
        path[h++]=0;//��¼�ֵ�����С��01���У�
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
      for(i=0;i<n-1;i++)//���г�ʼ��
        path[h++]=0,ans[i]=0;
        memset(vis,0,sizeof(vis));
      dfs(0);
      j=n-1;
      for(i=h-1;i>=n-1;i--)//ע�⵹��һ�¡�
        ans[j++]=path[i];
      sum=0;
      for(i=k;i<k+n;i++)
        sum=sum*2+ans[i];
        cout<<sum<<endl;
    }
    return 0;
}
