#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<queue>
#define MS(a,b) memset(a,b,sizeof(a))
typedef struct node
{
    node *left,*right;
    int data;
}*Tree;
 
int flag,num;
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
   if(abs(num)<=abs(T->data))insert1(T->left,num);
   else insert1(T->right,num);
}
 
void dfs(Tree T,int cnt)
{
    if(!flag)return ;//flag：为0表示不满足红黑树的条件。
    if(T==NULL)
    {  
        if(num==-1)num=cnt;//num：记录第一次到第一个叶子的黑色结点数目。
        else if(num!=cnt)flag=0;
        return ;
    }
    if(T->data>0)cnt++;
    else
    {
        if(T->left!=NULL&&T->left->data<0)flag=0;
        if(T->right!=NULL&&T->right->data<0)flag=0;
    }
    dfs(T->left,cnt);
    dfs(T->right,cnt);
}
int main()
{
   /* freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);*/
    int t,n,pre[50],i,vis;
    cin>>t;
    while(t--)
    {
      cin>>n;
      T=NULL;
      for(i=1;i<=n;i++)
      {
          cin>>pre[i];
          insert1(T,pre[i]);
      }
       if(pre[1]<0){cout<<"No\n";continue;}
         flag=1;
         num=-1;
        dfs(T,0);
        if( flag)
            cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}