/*hihocoder #1175 : 拓扑排序·二*/
#include <iostream>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
#define maxn 100010
#define mod 142857
int k,n,m,in[maxn],c[maxn];
int s[maxn],ans;
queue<int>q;
vector<int>mat[maxn];
int main()
{
    int i,j,a,b;
    cin>>n>>m>>k;
    memset(s,0,sizeof(s));
     for(i=0;i<k;i++)
       {
          cin>>c[i];
          s[c[i]]=1;
       }
    memset(in,0,sizeof(in));
      ans=0;
     for(i=0;i<m;i++)
     {
         cin>>a>>b;
        mat[a].push_back(b);
         in[b]++;
     }
     for(i=1;i<=n;i++)
     if(!in[i])
        q.push(i);
        int k,v;
     while(!q.empty())
     {
        k=q.front();
        q.pop();
     for(i=0;i<mat[k].size();i++)
      {
         v=mat[k][i];
         in[v]--;
         if(!in[v])
            q.push(v);
          s[v]=s[v]+s[k];
          s[v]=s[v]%mod;//注意该处也要求余
      }
     }
     for(i=1;i<=n;i++)
     {
         ans=ans+s[i];
         ans=ans%mod;
     }
     cout<<ans<<endl;
    return 0;
}
