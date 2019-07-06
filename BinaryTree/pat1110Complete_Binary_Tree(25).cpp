#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#include<vector>
#include<algorithm>
#include<queue>
#define MS(a,b) memset(a,b,sizeof(a))
int last,n,cnt;
vector<int>v;
struct node
{
    int left,right,fa;
}tree[200];
void bfs(int root)
{
    int rt;
    queue<int>q;
    q.push(root);
    while(!q.empty())
    {
      rt=q.front();
      q.pop();
     if(rt!=-1)
     {
        last=rt;//最后一个结点。
        cnt++;//访问过结点的数目。
     }
       if(rt==-1)break;
        q.push(tree[rt].left);
        q.push(tree[rt].right);
    }
}
int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif*/
    int i;
    char s1[5],s2[5];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        tree[i].left=tree[i].right=tree[i].fa=-1;
   for(i=0;i<n;i++)
   {
       cin>>s1>>s2;
       if(s1[0]!='-')
         {  sscanf(s1,"%d",&tree[i].left);//将字符转化为数字。
            tree[tree[i].left].fa=i;
         }
       else tree[i].left=-1;
       if(s2[0]!='-')
         {  sscanf(s2,"%d",&tree[i].right);
            tree[tree[i].right].fa=i;
         }
       else tree[i].right=-1;
   }
   int root=-1;
   for(i=0;i<n;i++)
    if(tree[i].fa==-1)
       {root=i;break;}
       cnt=0;
        bfs(root);
     if(cnt==n)
      printf("YES %d\n",last);
     else  printf("NO %d\n",root);
    return 0;
}