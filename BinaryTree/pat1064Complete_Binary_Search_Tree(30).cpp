#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#define MS(a,b) memset(a,b,sizeof(a))
int tree[2000],n,num[2000],j;
void inorder(int root)
{
   int lchild=root*2,rchild=root*2+1;
   if(root>n)return ;
   inorder(lchild);
   tree[root]=num[j++];
   inorder(rchild);
}
int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif*/
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
     scanf("%d",&num[i]);
     sort(num+1,num+1+n);
      j=1;
     inorder(1);
     for(i=1;i<n;i++)
        printf("%d ",tree[i]);
        printf("%d\n",tree[i]);
    return 0;
}