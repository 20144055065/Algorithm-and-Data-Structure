#include <iostream>
#include <vector>
#include <algorithm>
#include<string.h>
using namespace std;
#include<stdio.h>
int bin[1005],n;
struct node{
	vector<int> sons;
};
vector<node> hobby(1001);
int findx(int x)
{
    int r=x;
    while(r!=bin[r])
        r=bin[r];
    return r;
}
void fun(int x,int y)
{
    int tx,ty;
    tx=findx(x);
    ty=findx(y);
    if(tx!=ty)
       bin[tx]=ty;
}
int main()
{
    int k,i,j,num,v[1005],ans[1005],sum=0,p[1005];
    cin>>n;
    for(i=0;i<1005;i++)
        bin[i]=i;
    for(i=0;i<n;i++)
    {
        scanf("%d:",&k);
        for(j=0;j<k;j++)
        {
           cin>>num;
           hobby[num].sons.push_back(i);//��ÿ�����ã���Щ�˹�ͬӵ����Щ���õ��˵ı�ż�������.
        }
    }
    for(i=0;i<=1000;i++)
        if(hobby[i].sons.size()!=0)
    {
        int a=hobby[i].sons[0];
       for(j=1;j<hobby[i].sons.size();j++)
       {
           int b=hobby[i].sons[j];
           fun(a,b);
       }
    }
    memset(ans,0,sizeof(ans));
    for(i=0;i<n;i++)
       v[i]=findx(i);
       for(i=0;i<n;i++)
         ans[v[i]]++;//ÿ�����ϵ�����
    sort(ans,ans+1005);
    int f=0;
    for(i=1004;i>-1;i--)
        if(ans[i]!=0)
        {
            sum++;//�ж��ٸ�����
            p[f++]=ans[i];
        }
    cout<<sum<<endl;
     for(i=0;i<f-1;i++)
           cout<<p[i]<<" ";
     cout<<p[i]<<endl;
    return 0;
}