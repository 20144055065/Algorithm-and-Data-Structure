 #include<iostream>
#include<string.h>
#include<stack>
#include<vector>
using namespace std;
#include<stdio.h>
#include<algorithm>
#include<queue>
#define MS(a,b) memset(a,b,sizeof(a))
vector<int>tree[30000];
int ans[10005],fa[10005],g[10005],j,mm,vis[10005];
int findx(int x)
{
   int r=x;
   if(r!=fa[r])
    fa[r]=findx(fa[r]);
   return fa[r];
}
void Union(int x,int y)
{
    int tx,ty;
    tx=findx(x);ty=findx(y);
    if(tx!=ty)
      fa[tx]=ty;
}
void dfs(int u,int depth)
{
    int i;
  if(tree[u].size()==0)return ;
  for(i=0;i<tree[u].size();i++)
  {
    if(!ans[tree[u][i]])//如果该节点深度未知
    {
        ans[tree[u][i]]=depth;//记录该节点的深度。
        dfs(tree[u][i],depth+1);//搜索该节点的子节点。
    }
  }
}
int main()
{
    int n,a,b,i,num,c,d;
      cin>>n;
   for(i=1;i<=n;i++)
      fa[i]=i;
   for(i=1;i<n;i++)
   {
     cin>>a>>b;
     tree[a].push_back(b);
     tree[b].push_back(a);
     Union(a,b);
   }
      num=0;
     for(i=1;i<=n;i++)
       if(fa[i]==i)num++;
      if(num!=1)
      printf("Error: %d components\n",num);
      else
      {  mm=-1;j=0;
         MS(ans,0);
         ans[1]=1;
         dfs(1,2);
        for(i=1;i<=n;i++)
        {
            if(mm<ans[i])
              mm=ans[i],c=i;
        }
        for(i=1;i<=n;i++)
            if(ans[i]==mm)
                g[j++]=i;
              MS(ans,0);
               mm=-1;
              ans[c]=1;
              dfs(c,2);
            for(i=1;i<=n;i++)
                if(mm<ans[i])
                    mm=ans[i];
              for(i=1;i<=n;i++)
                 if(ans[i]==mm)
                 g[j++]=i;
                sort(g,g+j);
                MS(vis,0);
            for(i=0;i<j;i++)
                if(!vis[g[i]])
        {    vis[g[i]]=1;
           printf("%d\n",g[i]);   
        }
      }
    return 0;
}
 