/*hdu acm 1116 Play on Words*/
#include <iostream>
using namespace std;
#include<string.h>
#include<algorithm>
#include<vector>
#include<stdio.h>
vector<int>mat[30];
int vis[30];
void dfs(int s)
{
    int i;
    vis[s]=1;
    for(i=0;i<mat[s].size();i++)
    {
        int v=mat[s][i];
        if(!vis[v])
        {
            vis[v]=1;
            dfs(v);
        }
    }
    return ;
}
int main()
{  //freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
    int t,n,i,a,b,in[30],out[30],v[30],m;
    char s[1005];
    cin>>t;
    while(t--)
    {
        cin>>n;
      for(i=0;i<30;i++)
        mat[i].clear();
        memset(v,0,sizeof(v));
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
      for(i=0;i<n;i++)
      {
         cin>>s;
         a=s[0]-'a'+1;
         b=s[strlen(s)-1]-'a'+1;
         mat[a].push_back(b);
         v[a]=v[b]=1;
         in[b]++,out[a]++;
      }
      m=0;
      for(i=0;i<30;i++)
        if(v[i])
        m++;
      int s1,s2,e2,h1,h2,h3;
      h1=h2=h3=0;
      for(i=1;i<27;i++)
         if(v[i])
      {
          if(in[i]==out[i]){h1++;s1=i;}
          if(in[i]-out[i]==1){h2++;e2=i;}
          if(in[i]-out[i]==-1){h3++;s2=i;}
      }
      if(h1!=m&&!(h2==1&&h3==1&&h1==m-2))
      {
          cout<<"The door cannot be opened.\n";
          continue;
      }
      memset(vis,0,sizeof(vis));
      if(h1==m)
        dfs(s1);
      else if(h2==1&&h3==1&&h1==m-2)
        dfs(s2);
      int sign=1;
       for(i=1;i<27;i++)
        if(v[i])
           if(!vis[i])
           {sign=0;break;}
      if(sign)cout<<"Ordering is possible.\n";
      else cout<<"The door cannot be opened.\n";
    }
   // fclose(stdin);fclose(stdout);
    return 0;
}
