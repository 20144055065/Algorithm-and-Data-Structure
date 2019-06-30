/*ccf201409-4最优配餐*/
  #include<iostream>
 #include<string.h>
 #include<queue>
 using namespace std;
 int n,m,k,d;
 int mat[1005][1005];
 int vis[1005][1005],dir[4][2]={1,0,-1,0,0,1,0,-1};
 struct node
 {
     int x,y,step;
 };
 queue<node>q;
 long long bfs()
 {
   int i,s=0;
   long long ans=0;
   struct node head,next;
   while(!q.empty())
   {
       head=q.front();
       q.pop();
       for(i=0;i<4;i++)
       {
          next.x=head.x+dir[i][0];
          next.y=head.y+dir[i][1];
          next.step=head.step+1;
          if(next.x<1||next.y<1||next.x>n||next.y>n)continue;
          if(!vis[next.x][next.y])
          {
              vis[next.x][next.y]=1;
              if(mat[next.x][next.y])//同下面的巧妙之处。
              {   s++;
                  ans=ans+next.step*mat[next.x][next.y];
                  if(s==k)return ans;//判断所有买家是否遍历完。
              }
              q.push(next);
          }
       }
   }
 }
 int main()
 {
    struct node head;
    int i,j,x1,y1,x2,y2,c2,x3,y3;
    cin>>n>>m>>k>>d;
    memset(mat,0,sizeof(mat));
    memset(vis,0,sizeof(vis));
     for(i=0;i<m;i++)
     {
         cin>>x1>>y1;
         head.x=x1;
         head.y=y1;
         head.step=0;
         vis[head.x][head.y]=1;
         q.push(head);
     }
     for(i=0;i<k;i++)
     {
         cin>>x2>>y2>>c2;
         mat[x2][y2]=c2;//这处很巧妙。
     }
     for(i=0;i<d;i++)
     {
         cin>>x3>>y3;
         vis[x3][y3]=1;
     }
     cout<<bfs()<<endl;
     return 0;
 }
