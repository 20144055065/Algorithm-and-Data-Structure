#include<iostream>
#include<string.h>
using namespace std;
#include<stdio.h>
int n,m,fa[3000];
char mat[12][5]={"1010","1001","0110","0101","1100","0011","1011","1110","0111","1101","1111"};
/*四条边分别对应上下左右四个接口，若接口存在则为1，否则为0；*/
char mp[55][55];
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
    tx=findx(x);
    ty=findx(y);
    if(tx!=ty)
        fa[tx]=ty;
}
int main()
{
   int i,j,a,x,y,z,sum;
    while(cin>>n>>m)
    {
        if(n==-1&&m==-1)break;
        for(i=0;i<2600;i++)
            fa[i]=i;
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
          cin>>mp[i][j];
        for(i=0;i<n;i++)
          for(j=0;j<m;j++)
        {
            x=mp[i][j]-'A';
            y=mp[i][j+1]-'A';
            z=mp[i+1][j]-'A';
           if(j+1<m&&mat[x][3]=='1'&&mat[y][2]=='1')//判断左右接口是否重合。
                   Union(i*m+j,i*m+j+1);   
           if(i+1<n&&mat[x][1]=='1'&&mat[z][0]=='1')//判断上下接口是否重合。
                   Union(i*m+j,(i+1)*m+j);
        }
        sum=0;
       for(i=0;i<n*m;i++)
       {
         if(fa[i]==i)//找出哪个方块没有合并过。   
            sum++;
       }
        cout<<sum<<endl;
    }
    return 0;
}