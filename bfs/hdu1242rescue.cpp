/*hdu1242rescue*/
#include<iostream>
#include<string.h>
using namespace std;
#include<queue>
int m,n,vis[205][205];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
char mat[205][205];
struct node
{
    int x,y,step;
};
bool operator <(node a,node b)
{
    return a.step>b.step;


}
void bfs(int x,int y)
{  int i;
   priority_queue<node>q;
   struct node p,e;
   e.x=x;
   e.y=y;
   e.step=0;
   vis[e.x][e.y]=1;
   q.push(e);
   while(!q.empty())
   {
       e=q.top();
       q.pop();
       if(mat[e.x][e.y]=='r'){cout<<e.step<<endl;return ;}
       for(i=0;i<4;i++)
       {
            p.x=e.x+dir[i][0];
            p.y=e.y+dir[i][1];
            if(p.x<=0||p.x>m||p.y<=0||p.y>n||mat[p.x][p.y]=='#')continue;
            if(!vis[p.x][p.y])
            {
                if(mat[p.x][p.y]=='x')
                {
                    vis[p.x][p.y]=1;
                    p.step=e.step+2;
                    q.push(p);
                }
                if(mat[p.x][p.y]=='r'||mat[p.x][p.y]=='.')
                {
                    vis[p.x][p.y]=1;
                    p.step=e.step+1;
                    q.push(p);
                }
            }
       }
   }
   cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
}
int main()
{
    int i,j,i1,j1;
    while(cin>>m>>n)
    {memset(vis,0,sizeof(vis));
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
            {cin>>mat[i][j];
                if(mat[i][j]=='a')
            i1=i,j1=j;
            }
        bfs(i1,j1);
    }
    return 0;
}
