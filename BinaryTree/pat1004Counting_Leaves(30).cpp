#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
#include<queue>
#define MS(a,b) memset(a,b,sizeof(a))
#include<vector>
#include<algorithm>
vector<int>tree[200];
int ans[200],mm;
void dfs(int u,int depth)
{
    int i;
     mm=max(mm,depth);
  if(tree[u].size()==0)//如果为叶子结点
  {
      ans[depth]++;//该层数目+1；
      return ;
  }
 for(i=0;i<tree[u].size();i++)
    dfs(tree[u][i],depth+1);
}
int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif*/
    int n,m,id,k,num,i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
       scanf("%d %d",&id,&k);
       for(j=0;j<k;j++)
       {
           scanf("%d",&num);
           tree[id].push_back(num);
       }
    }
     MS(ans,0);
     mm=-1;
     dfs(1,1);
   for(i=1;i<mm;i++)
    printf("%d ",ans[i]);
    printf("%d\n",ans[i]);
    return 0;
}