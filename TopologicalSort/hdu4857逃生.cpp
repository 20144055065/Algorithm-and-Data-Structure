/*hdu 4857 逃生*/
#include<iostream>
#include<stdio.h>
using namespace std;
#include<string.h>
#include<vector>
#include<queue>
#define MS(a,b) memset(a,b,sizeof(a))
#include<map>
#include<algorithm>
int t,n,m,head[30005],in[30005],f;
vector<int>G;
struct node
{
 int s,e;
}p[100005];
struct hyf
{
    int e,next;
}edge[100005];
bool cmp(node a,node b)
{
    if(a.s==b.s)return a.e>b.e;
    return a.s>b.s;
}
void add(int s,int e)
{
    edge[f].e=e;
    edge[f].next=head[s];
    head[s]=f++;
}
int main()
{
    int i;
    scanf("%d",&t);
    while(t--)
    {
     scanf("%d %d",&n,&m);
       for(i=0;i<m;i++)
         scanf("%d %d",&p[i].s,&p[i].e);
         p[i].s=50000,p[i].e=50001;
         sort(p,p+m,cmp);
         MS(head,-1);MS(in,0);
           f=0;
       for(i=0;i<m;i++)
       {
           if(p[i].s==p[i+1].s&&p[i].e==p[i+1].e)
                continue;//去掉重复边
            add(p[i].e,p[i].s);
           in[p[i].s]++;
       }
    priority_queue<int,vector<int>,less<int> >q;//最大值优先
 /* priority_queue<int,vector<int>,greater<int> >q;最小值优先**/
        G.clear();
      for(i=1;i<=n;i++)
       if(!in[i])
       {
          q.push(i);
       }
      while(!q.empty())
      {   int v;
          int cur=q.top();
              q.pop();
            G.push_back(cur);
       for(i=head[cur];i!=-1;i=edge[i].next)
         {
            v=edge[i].e;
            in[v]--;
            if(!in[v])
              q.push(v);
         }
      }
      for(i=G.size()-1;i>0;i--)
         printf("%d ",G[i]);
         printf("%d\n",G[i]);
    }
    return 0;
}
