#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#include<vector>
#include<algorithm>
#include<queue>
#define MS(a,b) memset(a,b,sizeof(a))
vector<int>v1,v2;
struct node
{
    int left,right,fa;
}tree[2000];
void bfs(int root)
{
  int rt;
  queue<int>q;
  q.push(root);
  while(!q.empty())
  {
     rt=q.front();
     q.pop();
     v1.push_back(rt);
     if(tree[rt].left!=-1)
        q.push(tree[rt].left);
     if(tree[rt].right!=-1)
        q.push(tree[rt].right);
  }
}
void inorder(int root)
{
   if(tree[root].left!=-1)
        inorder(tree[root].left);
     v2.push_back(root);
    if(tree[root].right!=-1)
        inorder(tree[root].right);
}
int main()
{
    int n,i;
    char s1,s2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        tree[i].fa=-1;
   for(i=0;i<n;i++)
   {
       cin>>s1>>s2;
       if(s1!='-')
         {  tree[i].right=s1-'0';
            tree[s1-'0'].fa=i;
         }
       else tree[i].right=-1;
       if(s2!='-')
         {  tree[i].left=s2-'0';
            tree[s2-'0'].fa=i;
         }
       else tree[i].left=-1;
   }
   int root;
   for(i=0;i<n;i++)
    if(tree[i].fa==-1)
       {root=i;break;}
     bfs(root);
   for(i=0;i<v1.size()-1;i++)
    printf("%d ",v1[i]);
    printf("%d\n",v1[i]);
     inorder(root);
    for(i=0;i<v2.size()-1;i++)
    printf("%d ",v2[i]);
    printf("%d\n",v2[i]);
    return 0;
}