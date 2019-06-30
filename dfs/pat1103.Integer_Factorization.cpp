/*pat 1103. Integer Factorization*/
#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
#include<map>
#include<queue>
#include<string.h>
#define MS(a,b) memset(a,b,sizeof(a))
int n,k,p,num[30],S,maxn=-1;
vector<int>v;
vector<int>ans;
/*
start:刚开始的数。
cnt:个数
reminder：表示当前剩余的和。
num[i]:i^p的值。
*/
void dfs(int start,int cnt,int reminder)
{
    int i;
    if(cnt==0)
    {
     if(reminder==0)
     {
         if(S>maxn)
         {
             S=maxn;
             ans.clear();
           for(i=0;i<v.size();i++)
             ans.push_back(v[i]);
         }
         else if(S==maxn)
         {
           for(i=0;i<v.size();i++)
            if(ans[i]<v[i])
              break;
           if(i!=v.size())
            {
                ans.clear();
           for(i=0;i<v.size();i++)
             ans.push_back(v[i]);
            }
         }
     }
     return ;
    }
    for(i=start;i<21;i++)
    {
        int k=num[i];
     if(k>reminder)break;
     v.push_back(i);
        S=S+i;
       dfs(i,cnt-1,reminder-k);
        S=S-i;
      v.pop_back();//回溯的时候要把这个点删掉。
    }
}
int main()
{
   int i,j;
   scanf("%d %d %d",&n,&k,&p);
    for(i=1;i<21;i++)
    {
       num[i]=1;
      for(j=0;j<p;j++)
       num[i]=num[i]*i;
    }
    S=0;
    dfs(1,k,n);
     if(ans.empty())
        printf("Impossible\n");
    else
    {
      printf("%d = ",n);
      for(i=ans.size()-1;i>0;i--)
       printf("%d^%d + ",ans[i],p);
      printf("%d^%d\n",ans[i],p);
    }
    return 0;
}
