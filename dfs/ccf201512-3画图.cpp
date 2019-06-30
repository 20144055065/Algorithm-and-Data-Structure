/*ccf 201512-3 »­Í¼*/
#include <iostream>
#include<string.h>
using namespace std;
#include<stdio.h>
#include<algorithm>
#define MS(a,b) memset(a,b,sizeof(a))
int dir[4][2]={1,0,-1,0,0,1,0,-1},n,m,vis[200][200],v[200][200];
char mat[200][200];
void dfs(int i,int j,char s)
{
    int tx,ty,k;
    mat[i][j]=s;
    for(k=0;k<4;k++)
    {
        tx=i+dir[k][0];
        ty=j+dir[k][1];
   if(tx<0||tx>=m||ty<0||ty>=n)continue;
   if(mat[tx][ty]=='-'||mat[tx][ty]=='|'||mat[tx][ty]=='+'||mat[tx][ty]==s)
       continue;
        dfs(tx,ty,s);
    }
}
int main()
{
    char s;
    int q,i,h,x1,y1,x2,y2,x,y,j,k,h1,h2;
    int vis[200][200],v[200][200];
    cin>>n>>m>>q;
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
        mat[i][j]='.';
    for(i=0;i<q;i++)
    {
      cin>>h;
      if(h==1)
      {
        cin>>x>>y>>s;
        dfs(m-1-y,x,s);
      }
      else
      {
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2)
        {
            h1=max(m-1-y1,m-1-y2);
            h2=min(m-1-y1,m-1-y2);
          for(j=h2;j<=h1;j++)
          {
       if(mat[j][x1]=='.'||mat[j][x1]=='|'||mat[j][x1]=='A'&&mat[j][x1]>='Z'||mat[j][x1]=='a'&&mat[j][x1]=='z')
           mat[j][x1]='|';
        else
            mat[j][x1]='+';
          }
        }
        if(y1==y2)
        {
            h1=max(x1,x2);
            h2=min(x1,x2);
          for(j=h2;j<=h1;j++)
          {
         if(mat[m-1-y1][j]=='.'||mat[m-1-y1][j]=='-'||mat[m-1-y1][j]>='A'&&mat[m-1-y1][j]<='Z'||mat[m-1-y1][j]>='a'&&mat[m-1-y1][j]<='z')
               mat[m-1-y1][j]='-';
          else
            mat[m-1-y1][j]='+';

          }

        }
      }
    }
    for(i=0;i<m;i++)
    {
       for(j=0;j<n;j++)
        cout<<mat[i][j];
       cout<<endl;
    }
    return 0;
}

