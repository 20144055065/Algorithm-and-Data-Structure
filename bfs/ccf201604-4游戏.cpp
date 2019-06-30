/*ccf 201604-4 ��Ϸ*/
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
         if(!vis[e.step][e.x][e.y])//���������п���ĳһ����ĳһʱ���ظ�������
         {
           vis[e.step][e.x][e.y]=1;
          if(e.x<1||e.y<1||e.x>n||e.y>m||e.step>300)continue;
          /*���û��Σ�ո�Ļ���������Ҫ200��ʱ�䵥λ��ab֮���ʱ�����100��ʱ�䵥λ��ʱ����಻����300����λ*/
          if(!flag[e.step][e.x][e.y])//�жϸø��ʱ���Ƿ���Σ�յ�
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
