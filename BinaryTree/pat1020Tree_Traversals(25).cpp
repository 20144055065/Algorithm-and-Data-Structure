/*pat 1020. Tree Traversals (25)*/
#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
#include<queue>
#define MS(a,b) memset(a,b,sizeof(a))
typedef struct node
{
    int data;
    node *left,*right;
}*Tree;
Tree T;
int ans[100],in[100],post[100],n;
void Build(int l1,int r1,int l2,int r2,Tree &T)
{
    int i;
    T=new node();
    for(i=l1;i<=r1;i++)//求根结点
        if(in[i]==post[r2])
              break;
        T->data=post[r2];
    if(i==l1)
        T->left=NULL;
    else Build(l1,i-1,l2,l2+i-l1-1,T->left);//递归求左子树
    if(i==r1)
       T->right=NULL;
    else Build(i+1,r1,r2-(r1-i),r2-1,T->right);//递归求右子树
}
int j;
void levelorder(Tree  T)
{
     queue<Tree>q;
     q.push(T);
     while(!q.empty())
     {
        Tree root=q.front();
        q.pop();
        ans[j++]=root->data;
        if(root->left!=NULL)
            q.push(root->left);
        if(root->right!=NULL)
            q.push(root->right);
     }
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
         scanf("%d",&post[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&in[i]);
    Build(1,n,1,n,T);
    j=0;
    levelorder(T);
    for(i=0;i<j-1;i++)
     printf("%d ",ans[i]);
     printf("%d\n",ans[i]);
    return 0;
}
