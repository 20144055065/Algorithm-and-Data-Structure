/* hihocoder #1176 : 欧拉路·一*/
#include<iostream>
using namespace std;
#include<string.h>
#include<algorithm>
#include<vector>
#define maxn 10010
vector<int>mat[maxn];
int n,m,vis[maxn],degree[maxn];
void dfs(int s)//判断是否连通
{
   int i,v;
   vis[s]=1;
 for(i=0;i<mat[s].size();i++)
 {
     v=mat[s][i];
     if(!vis[v])
     {
      vis[v]=1;
       dfs(v);
     }
 }
}
int main()
{
    int a,b,i,h1,h2;
    cin>>n>>m;
 memset(degree,0,sizeof(degree));
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        mat[a].push_back(b);
        mat[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    memset(vis,0,sizeof(vis));
    dfs(1);
    h1=1;h2=0;
    int ans=0;
    for(i=1;i<=n;i++)
    {
        if(degree[i]%2==1)
          ans++;
        if(!vis[i])h1=0;
    }
    if(ans==0||ans==2)h2=1;
    if(h1&&h2)
        cout<<"Full\n";
    else cout<<"Part\n";
    return 0;
}
