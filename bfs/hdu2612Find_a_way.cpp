/*hdu 2612 Find a way*/
#include<iostream>
using namespace std;
#include<string.h>
#include<queue>
char mat[205][205];
int n,m,dir[4][2]={1,0,0,1,-1,0,0,-1};
int s,h,vis[205][205],ans[205][205];
struct node
{
    int x,y,sum;
};
void bfs(int x,int y)
{
    int i;
    queue<node>q;
    struct node head,next;
    head.x=x;
    head.y=y;
    head.sum=0;
    vis[head.x][head.y]=1;
    q.push(head);
    while(!q.empty())
    {
        head=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            next.x=head.x+dir[i][0];
            next.y=head.y+dir[i][1];
            next.sum=head.sum+1;
                if(mat[next.x][next.y]=='#'||next.x<=0||next.y<=0||next.x>n||next.y>m)continue;
                if(mat[next.x][next.y]=='@'&&!vis[next.x][next.y])
                {
                    vis[next.x][next.y]=1;
                    ans[next.x][next.y]+=next.sum;
                    q.push(next);
                }
                if(mat[next.x][next.y]=='.'&&!vis[next.x][next.y])
                {vis[next.x][next.y]=1;
                   q.push(next);
                }


        }
    }
    return ;
}
int main()
{
    int i,j,min,i1,j1,i2,j2;
    while(cin>>n>>m)
    {min=9999999;
    memset(vis,0,sizeof(vis));
    memset(ans,0,sizeof(ans));
        for(i=1;i<n+1;i++)
            for(j=1;j<m+1;j++)
            {
                cin>>mat[i][j];
                if(mat[i][j]=='Y')
                    i1=i,j1=j;
                if(mat[i][j]=='M')
                    i2=i,j2=j;
            }
              bfs(i1,j1);
            memset(vis,0,sizeof(vis));
              bfs(i2,j2);
               for(i=1;i<n+1;i++)
                 for(j=1;j<m+1;j++)
                    if(mat[i][j]=='@'&&ans[i][j]!=0)//这处坑爹，少写了ans[i][j]!=0，因为有可能有几处KFC根本无法到达，求最小值时会为0，把无法到达的也给算进去。
                 {
                     if(min>ans[i][j])
                        {min=ans[i][j];}
                 }
               cout<<min*11<<endl;
    }
    return 0;
}
