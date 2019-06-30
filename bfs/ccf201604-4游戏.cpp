/*ccf 201604-4 游戏*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#define MS(a,b) memset(a,b,sizeof(a))
#include<queue>
#include<vector>
#include<map>
#include<stack>
using namespace std;
int mat[105][105],flag[400][200][200];
int n,m,t,vis[400][200][200];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
struct node
{
    int x,y,step;
};
void bfs(int x,int y)
{
    int i,j=0;
   queue<node>q;
  struct node s,e;
    s.x=x;
    s.y=y;
    s.step=0;
    q.push(s);
   while(!q.empty())
   {
      s=q.front();
      q.pop();
      if(s.x==n&&s.y==m)
      {
        printf("%d\n",s.step);
        return ;
      }
     for(i=0;i<4;i++)
     {
         e.x=s.x+dir[i][0];
         e.y=s.y+dir[i][1];
         e.step=s.step+1;
         if(!vis[e.step][e.x][e.y])//搜索过程中可能某一格在某一时刻重复搜索。
         {
           vis[e.step][e.x][e.y]=1;
          if(e.x<1||e.y<1||e.x>n||e.y>m||e.step>300)continue;
          /*如果没有危险格的话，最多最快要200个时间单位，ab之间的时间最多100个时间单位，时间最多不超过300个单位*/
          if(!flag[e.step][e.x][e.y])//判断该格该时刻是否是危险的
               q.push(e);
         }

     }
   }
}
int main()
{
   int r,c,a,b,i,j;
   scanf("%d%d%d",&n,&m,&t);
   MS(vis,0);
   MS(flag,0);
      for(i=0;i<t;i++)
   {
       scanf("%d%d%d%d",&r,&c,&a,&b);
      for(j=a;j<=b;j++)
        flag[j][r][c]= 1;
   }
     bfs(1,1);
    return 0;
}
