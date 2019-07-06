#include<iostream>
using namespace std;
#include<string.h>
#include<vector>
#define MS(a,b) memset(a,b,sizeof(a))
int n,vis[100010],dis[100010],rt,mm,m;
vector<int>tree[100010];
void dfs(int u)
{
  int i,v;
  if(mm<dis[u])
  {
    mm=dis[u];
    rt=u;
  }
  for(i=0;i<tree[u].size();i++)
  {
       v=tree[u][i];
       if(!vis[v])
       {
          vis[v]=1;
      dis[v]=dis[u]+1;
          dfs(v);
       }
  }
}
int main()
{
    int i,num,num1;
    cin>>n>>m;
    for(i=2;i<=n;i++)
    {
        cin>>num;
      tree[i].push_back(num);
      tree[num].push_back(i);
    }
    for(i=1;i<=m;i++)
    {
        cin>>num1;
      tree[n+i].push_back(num1);
      tree[num1].push_back(n+i);
    }
    mm=-1;
    MS(vis,0);
    MS(dis,0);
    vis[1]=1;
    dfs(1);
    mm=-1;
    MS(vis,0);
    MS(dis,0);
    vis[rt]=1;
    dfs(rt);
    cout<<mm<<endl;
    return 0;
}