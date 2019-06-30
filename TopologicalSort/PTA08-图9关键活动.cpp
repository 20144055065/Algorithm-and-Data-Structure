/*PTA 08-ͼ9 �ؼ��*/
#include<iostream>
#include<queue>
using namespace std;
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
#define MS(a,b) memset(a,b,sizeof(a))
int n,m,dfn[200][200],dis[200][200];
int vl[200],ve[200],in[200],out[200];
int mat[200][200],sum,ans;
vector<int>G[300],G1[300];
struct node
{
    int s,e,DFN;
}p[300];
bool cmp(node a,node b)
{  if(a.s==b.s)
     return a.DFN>b.DFN;
   return a.s<b.s;
}
void bfs_early()
{  int i;
    queue<int>q;
    for(i=1;i<=n;i++)
        if(!in[i])
           q.push(i);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
     for(i=0;i<G[cur].size();i++)
     {
         int v=G[cur][i];
         ve[v]=max(ve[v],ve[cur]+dis[cur][v]);
         in[v]--;
        if(!in[v])
        {
           q.push(v);
           ans++;
        }

     }
    }
}
void bfs_later()
{
  int i;
  queue<int>q;
  for(i=1;i<=n;i++)
    if(!out[i])
      q.push(i),vl[i]=sum;
  while(!q.empty())
  {
    int cur=q.front();
    q.pop();
    for(i=0;i<G1[cur].size();i++)
    {
        int v=G1[cur][i];
        vl[v]=min(vl[v],vl[cur]-dis[cur][v]);
        out[v]--;
        if(!out[v])
            q.push(v);
    }
  }
}
int main()
{
   int i,ss,ee,d;
   ans=0 ;
  cin>>n>>m;
  MS(in,0);
  MS(out,0);
  MS(mat,0);
  MS(ve,0);
  for(i=1;i<=m;i++)
  {
    cin>>ss>>ee>>d;
    G[ss].push_back(ee);
    G1[ee].push_back(ss);
    mat[ss][ee]=1;
    dis[ss][ee]=dis[ee][ss]=d;
    in[ee]++;out[ss]++;
    dfn[ss][ee]=i;
  }
  queue<int>q;
  for(i=1;i<=n;i++)
     if(!in[i])
      {
        q.push(i);
        ans++;
      }
   for(i=1;i<=n;i++)
      vl[i]=99999;
    bfs_early();
   if(ans!=n)cout<<"0\n";
   else
   {

         sum=0;
     for(i=1;i<=n;i++)
        if(!out[i])
          sum=max(sum,ve[i]);//���յ�ʱȫ����������Ҫ��ʱ�䡣
       bfs_later();
       cout<<sum<<endl;
       int j,k=0;
       for(i=1;i<=n;i++)
       {
         if(vl[i]==ve[i])
         {
             for(j=1;j<=n;j++)
              if(mat[i][j]&&vl[j]==ve[j]&&vl[j]-dis[i][j]==ve[i])
//һ��ʼvl[j]-dis[i][j]==ve[i]�������ûд�����˺ö�Σ�����Ϊ����ؼ����Ϳ��������ٶ��Ŀ�����������ؼ��û��ϸ������
                 p[k].s=i,p[k].e=j,p[k].DFN=dfn[i][j],k++;
         }
       }
        sort(p,p+k,cmp);
       for(i=0;i<k;i++)
         cout<<p[i].s<<"->"<<p[i].e<<endl;
   }
    return 0;
}
