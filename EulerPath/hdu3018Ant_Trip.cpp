/*hdu acm 3018 Ant Trip*/
#include <iostream>
using namespace std;
#include<string.h>
#include<algorithm>
#include<vector>
#include<stdio.h>
#define maxn 100005
int bin[maxn];
int vis[maxn],n,m;
int findx(int x)
{
    if(x!=bin[x])
        return bin[x]=findx(bin[x]);
    return bin[x];
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
{  //freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
    int i,a,b,deg[maxn],ans,v[maxn],g,num[maxn];
    while(cin>>n>>m)
    {
        memset(deg,0,sizeof(deg));
        memset(vis,0,sizeof(vis));
        memset(num,0,sizeof(num));
        for(i=0;i<=n;i++)
            bin[i]=i;
       for(i=0;i<m;i++)
       {
         cin>>a>>b;
         fun(a,b);
        deg[a]++,deg[b]++;
       }
       memset(v,0,sizeof(v));
       int j=0;
       for(i=1;i<=n;i++)
       {
         g=findx(i);
         if(!vis[g])
         {
             v[j++]=g;
             vis[g]=1;
         }
         if(deg[i]%2==1)
            num[g]++;
       }
       ans=0;
       for(i=0;i<j;i++)//��j����ͨ�顣
       {
           int k=v[i];
           //cout<<k<<" "<<deg[k]<<" "<<num[k]<<endl;
           if(!deg[k])continue;//�����Ϊ0��˵������һ�������ĵ㣬���Ե���
           if(deg[k]&&num[k]==0)ans++;//����Ȳ�Ϊ0����û�������ȵĶ��㣬����ŷ����·��ֻ��Ҫ1��
          else ans=ans+num[k]/2;//����Ȳ�Ϊ0�Ҵ��������ȵĶ��㣬��ans=�����ȵĶ���/2��
       }
      cout<<ans<<endl;
    }
   // fclose(stdin);fclose(stdout);
    return 0;
}
