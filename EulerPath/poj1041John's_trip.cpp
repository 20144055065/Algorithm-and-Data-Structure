/*poj 1041 John's trip*/
#include <iostream>
using namespace std;
#include<string.h>
#include<algorithm>
#include<stdio.h>
int mat[45][2000],vis[2000],m,path[2000],h;
void dfs(int u)
{
    int i,v;
    for(i=1;i<=m;i++)
    {
       v=mat[u][i];
       if(v&&!vis[i])
       {
         vis[i]=1;
         dfs(v);
      path[h++]=i;
       }
    }

}
int main()
{  //freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
    int a,b,id,deg[2000],i,st;//数组开的大一点，不然会错。
   while(~scanf("%d %d",&a,&b))
   {
        m=0;
       st=min(a,b);//上面红色字体标注的就是起始点。
     if(a==0&&b==0)break;
     scanf("%d",&id);
     memset(vis,0,sizeof(vis));
     memset(mat,0,sizeof(mat));
     memset(deg,0,sizeof(deg));
     while(1)
     {
       mat[a][id]=b,mat[b][id]=a;//两点之间存在多条路，这样记录很方便。
       deg[a]++,deg[b]++;
       m=max(m,id);
       scanf("%d %d",&a,&b);
       if(a==0&&b==0)break;
       scanf("%d",&id);
     }
     int sign=1;
     for(i=1;i<=45;i++)
        if(deg[i]%2==1)
           {sign=0;break;}
           if(!sign )
            printf("Round trip does not exist.\n");
           else
           {
               h=0;
               dfs(st);
               for(i=h-1;i>0;i--)
                printf("%d ",path[i]);
               printf("%d\n",path[i]);
           }
   }

   // fclose(stdin);fclose(stdout);
    return 0;
}
