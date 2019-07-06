#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#define MS(a,b) memset(a,b,sizeof(a))
int ans[3000],mm;
typedef struct node
{
    int data;
    node *left,*right;
}*Tree;
Tree T;
void insert1(Tree &T,int num)
{
    if(T==NULL)
    {
        T=new node();
        T->data=num;
        T->left=NULL;
        T->right=NULL;
      return ;
    }
    if(num<=T->data)insert1(T->left,num);
    else insert1(T->right,num);
}
void dfs(Tree T,int depth)
{
    if(T==NULL)return ;
    ans[depth]++;
    mm=max(mm,depth);
    dfs(T->left,depth+1);
    dfs(T->right,depth+1);
}
int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif*/
    int n,num[3000],i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      scanf("%d",&num[i]);
     insert1(T,num[i]);
    }
      MS(ans,0);mm=-1;
      dfs(T,0);
      printf("%d + %d = %d\n",ans[mm],ans[mm-1],ans[mm]+ans[mm-1]);
     return 0;
}