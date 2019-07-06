#include <iostream>
#include<string.h>
#include<stack>
#include<vector>
using namespace std;
#include<stdio.h>
#include<algorithm>
#include<queue>
vector<int>tree[150000];
int n,mm,ans[150000];
double p,r,t;
void dfs(int u,int depth)
{
    int i;
  if(tree[u].size()==0)
  {
      mm=min(mm,depth);
      ans[depth]++;
      return ;
  }
  for(i=0;i<tree[u].size();i++)
  {
     dfs(tree[u][i],depth+1);
  }
}
int main()
{
    int i,k,j,num;
   cin>>n>>p>>r;
    for(i=0;i<n;i++)
    {
      cin>>k;
     for(j=0;j<k;j++)
      {
       cin>>num;
       tree[i].push_back(num);
      }
    }
    mm=999999;
    dfs(0,1);
     t=1;
    for(i=1;i<mm;i++)
     t=t*(1+r*1.0/100);
     printf("%.4lf %d\n",t*p,ans[mm]);
    return 0;
}