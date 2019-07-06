#include <stdio.h>
#include<string.h>
int dp[1005],bin[1005];
struct hyf
{
    int w1[1005],v1[1005];
}p[1005];
int max(int a,int b)
{
    if(a>b)return a;
    else return b;
}
int findx(int x)
{
    int r=x,j,k;
    while(r!=bin[r])
        r=bin[r];
    return r;
}
void fun(int x,int y)
{
    int tx,ty;
    tx=findx(x);
    ty=findx(y);
    if(tx!=ty)
        bin[tx]=ty;
}
int main()
{
   int n,m,h,k,i,j,vv[1005],ww[1005];
   int a,b,v[1005],num[1005],s=0;
    memset(dp,0,sizeof(dp));
    memset(num,0,sizeof(num));
    scanf("%d %d %d",&n,&m,&h);
    for(i=1;i<=n;i++)
        bin[i]=i,scanf("%d %d",&vv[i],&ww[i]);
    for(i=0;i<h;i++)
    {
        scanf("%d %d",&a,&b);
        fun(a,b);
    }
    for(i=1;i<=n;i++)
    {
        if(bin[i]==i)s++;
        v[i]=findx(i);//同一组的v[i]值相等
    }
       int i1=0,j1=0;
        for(i=1;i<=n;i++)//把组分好
        { if(bin[i]==i)
        {
             for(j=1;j<=n;j++)
              if(v[j]==i)
              {
                 p[i1].v1[j1]=vv[j];
                 p[i1].w1[j1]=ww[j];
                 num[i1]++;
                 j1++;
              }
              i1++;j1=0;
        }
         }
     for(i=0;i<s;i++)
     {
        for(j=m;j>0;j--)
         for(k=0;k<num[i];k++)
            if(j>=p[i].w1[k])
            {
                dp[j]=max(dp[j],dp[j-p[i].w1[k]]+p[i].v1[k]);
            }
     }
      printf("%d\n",dp[m]);
    return 0;
}