/*hihocoder #1181 : Å·À­Â·¡¤¶þ*/
#include <iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
#define maxn 5005
int mat[1005][1005],path[maxn];
int degree[maxn],h,n,m,stackn[maxn],top;
void dfs(int u)
{
    int i;
    stackn[top++]=u;
    for(i=1;i<=n;i++)
    {
        if(mat[u][i]>0)
        {
            mat[u][i]--;
            mat[i][u]--;
            dfs(i);
            break;
        }
    }
}
void fleury(int u)
{
    int bridge,i;
    stackn[top++]=u;
    while(top>0)
    {
        bridge=1;
        for(i=1;i<=n;i++)
            if(mat[stackn[top-1]][i]>0)
        {
            bridge=0;
            break;
        }
        if(bridge)
            path[h++]=stackn[--top];
        else dfs(stackn[--top]);
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
 int i,a,b;
  cin>>n>>m;
  memset(degree,0,sizeof(degree));
  for(i=0;i<m;i++)
  {
      cin>>a>>b;
  mat[a][b]++;mat[b][a]++;
     degree[a]++;
     degree[b]++;
  }
  int site=1;
  for(i=1;i<=n;i++)
    if(degree[i]%2==1)
    {
        site=i;
        break;
    }
    h=0;top=0;
    fleury(site);
    for(i=0;i<h;i++)
        cout<<path[i]<<" ";
    cout<<endl;
    //fclose(stdin);
	//fclose(stdout);
    return 0;
}
