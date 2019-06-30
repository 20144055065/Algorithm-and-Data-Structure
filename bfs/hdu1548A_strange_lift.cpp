/*hdu1548A_strange_lift*/
 #include<iostream>
#include<queue>
using namespace std;
struct node
{
    int x;
    int t;
}n1,n2,m;
int vis[205],h[205],flag;
int main()
{
    int n,a,b,i;
    while(cin>>n&&n)
    {flag=0;
        cin>>a>>b;
        for(i=1;i<n+1;i++)
           {
               cin>>h[i];
               vis[i]=0;
           }
           n1.x=a;n1.t=0;
        queue<node>q;
        q.push(n1);
        while(!q.empty())
        {
            m=q.front();
            q.pop();
            if(m.x==b)
            {
                flag=1;
                break;
            }
            n1.x=m.x-h[m.x];
            n2.x=m.x+h[m.x];
            if(n1.x>=0&&n1.x<=b&&!vis[n1.x])
            {
                n1.t=m.t+1;
                vis[n1.x]=1;
                 q.push(n1);
            }
            if(n2.x>=0&&n2.x<=b&&!vis[n2.x])
            {
                n2.t=m.t+1;
                vis[n2.x]=1;
                 q.push(n2);
            }
        }
        if(flag==1)cout<<m.t<<endl;
        else cout<<"-1\n";
    }
    return 0;
}
