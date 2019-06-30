/*hdu 1956 Sightseeing tour�����ͼŷ����·��*/
#include<iostream>
#include<stdio.h>
using namespace std;
#include<queue>
#include<string.h>
#include<math.h>
#include<algorithm>
#define MS(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
int head[50000],dis[3000],f,n,m,in[3000],out[3000];
struct node
{
    int to,next,w;
}edge[50000];
void add(int u,int v,int w)
{
  edge[f].to=v;
  edge[f].next=head[u];
  edge[f].w=w;
  head[u]=f++;
  edge[f].to=u;
  edge[f].next=head[v];
  edge[f].w=0;
  head[v]=f++;
}
int bfs()
{
  int i,x,v;
  MS(dis,0);
  dis[0]=1;
  queue<int>q;
  q.push(0);
  while(!q.empty())
  {
    x=q.front();
    q.pop();
    for(i=head[x];i!=-1;i=edge[i].next)
    {  v=edge[i].to;
      if(edge[i].w&&dis[v]==0)
      {
          dis[v]=dis[x]+1;
       if(v==n+1)return 1;
          q.push(v);
      }
    }
  }
  return 0;
}
int dfs(int s,int cur_flow)
{
    int i,v,tmp,dt=cur_flow;
    if(s==n+1)return cur_flow;
    for(i=head[s];i!=-1;i=edge[i].next)
    {
       v=edge[i].to;
       if(edge[i].w&&dis[s]==dis[v]-1)
       {
         int flow=dfs(v,min(dt,edge[i].w));
               edge[i].w-=flow;
               edge[i^1].w+=flow;
               dt-=flow;
       }
    }
    return cur_flow-dt;
}
int dinic()
{
  int ans=0;
  while(bfs())
    ans+=dfs(0,INF);
  return ans;
}
int main()
{
    int t,i,a,b,h,sign,g,sum,ans;
    cin>>t;
    while(t--)
    {   sum=sign=f=0;
        cin>>n>>m;
        MS(head,-1);
        MS(in,0);
        MS(out,0);
       for(i=0;i<m;i++)
       {
           cin>>a>>b>>h;
           in[b]++,out[a]++;
           if(h==0)
            add(a,b,1);
       }
      for(i=1;i<=n;i++)
      {
         int k=abs(in[i]-out[i]);
          if(k&1)
              sign=1;//����ÿ����Ķ�deg�����Ϊ��������Ϊ�������ĳ�����degΪ��������Ȼ������ŷ����·
         g=in[i]-out[i];
              if(g>0)
                 add(i,n+1,g/2);//���deg > 0, ����ȴ��ڳ��ȣ��� i ��һ������ T������Ϊ deg / 2
              else if(g<0)
              {
                 add(0,i,-g/2);//���deg < 0�������ȴ�����ȣ���S��һ������ i ������Ϊ(- deg ) / 2��
                 sum=sum-g/2;
              }
      }
      if(sign)cout<<"impossible\n";
      else
      {
          ans=dinic();
          if(sum==ans)//�����S���������л����أ���ŷ����·����
            cout<<"possible\n";
          else cout<<"impossible\n";
      }
    }
    return 0;
}
