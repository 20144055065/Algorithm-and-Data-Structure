#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#define MS(a,b) memset(a,b,sizeof(a))
int v1[200],j;
map<int,int>mp;
vector<int>v;
struct node
{
    int left,right,fa;
}tree[200];
void inorder(int root)
{    if(root==-1)return ;
    inorder(tree[root].left);
    v1[j++]=root;
    inorder(tree[root].right);
}
void bfs(int root)
{
   int rt;
   queue<int>q;
   q.push(root);
  while(!q.empty())
  {
    rt=q.front();
    q.pop();
    v.push_back(rt);
    if(tree[rt].left!=-1)
        q.push(tree[rt].left);
    if(tree[rt].right!=-1)
        q.push(tree[rt].right);
  }
}
int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif*/
    int n,a,b,i,root,num[200];
    scanf("%d",&n);
    for(i=0;i<n;i++)
       tree[i].fa=-1;
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        tree[i].left=a;tree[i].right=b;
        tree[a].fa=tree[b].fa=i;
    }
    for(i=0;i<n;i++)
       scanf("%d",&num[i]);
     sort(num,num+n);
    for(i=0;i<n;i++)
        if(tree[i].fa==-1)
     {root=i;break;}
       j=0;
     inorder(root);
     for(i=0;i<n;i++)
        mp[v1[i]]=num[i];
        bfs(root);
     for(i=0;i<v.size()-1;i++)
        printf("%d ",mp[v[i]]);
        printf("%d\n",mp[v[i]]);
     return 0;
}