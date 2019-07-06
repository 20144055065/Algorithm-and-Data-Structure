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
int v1[2000],v2[2000],ans[2000],n;
void insert1(Tree &T,int num)//½¨Á¢¶þ²æËÑË÷Ê÷
{
    int i;
    if(T==NULL)
    {  T=new node();
       T->data=num;
       T->left=NULL;
       T->right=NULL;
       return ;
    }
   if(num<T->data)
        insert1(T->left,num);
   else insert1(T->right,num);
}
void insert2(Tree &T,int num)//½¨Á¢¾µÏñ¶þ²æËÑË÷Ê÷
{
    int i;
    if(T==NULL)
    {  T=new node();
       T->data=num;
       T->left=NULL;
       T->right=NULL;
       return ;
    }
   if(num>=T->data)
        insert2(T->left,num);
   else insert2(T->right,num);
}
int j,k;
void preorder(Tree T,int v[])
{
   v[j++]=T->data;
   if(T->left!=NULL)
      preorder(T->left,v);
   if(T->right!=NULL)
      preorder(T->right,v);
}
void postorder(Tree T,int v[])
{
   if(T->left!=NULL)
      postorder(T->left,v);
   if(T->right!=NULL)
      postorder(T->right,v);
      v[k++]=T->data;
}
int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif*/
    int n,i,num[2000],sign1=0,sign2=0;
 
    scanf("%d",&n);
    Tree T1=NULL,T2=NULL;
    for(i=0;i<n;i++)
    {
      scanf("%d",&num[i]);
      insert1(T1,num[i]);
      insert2(T2,num[i]);
    }
    j=0;
    preorder(T1,v1);
    j=0;
    preorder(T2,v2);
    for(i=0;i<n;i++)
        if(v1[i]!=num[i])
        {sign1=1;break;}
     for(i=0;i<n;i++)
        if(v2[i]!=num[i])
        {sign2=1;break;}
        if(sign1&&sign2)
            printf("NO\n");
        else
        {k=0;
          if(!sign1&&sign2)
           postorder(T1,ans);
         else  
           postorder(T2,ans);
        printf("YES\n");
        for(i=0;i<k-1;i++)
          printf("%d ",ans[i]);
           printf("%d\n",ans[i]);
        }
    return 0;
}