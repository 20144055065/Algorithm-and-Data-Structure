 #include<stdio.h>
 #include<string.h>
 #include<iostream>
 using namespace std;
 #include<algorithm>
 int bin[100005],sign,a[100005];
 int findx(int x)
 {  int r=x,f;
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
     else sign=1;
 }
 int main()
 {
     int n,m,i,j,sum,h=1,vis[100005],f;
     while( scanf("%d %d",&n,&m)&&n>=0&&m>=0)
     {
           f=0;
       if(n==0&&m==0){printf("Case %d is a tree.\n",h++);continue;}
         sign=0;a[f++]=m;
         memset(vis,0,sizeof(vis));
         for(i=1;i<100005;i++)
            bin[i]=i;
            vis[n]=1;vis[m]=1;
           fun(n,m);
        while((m+n)!=0)
        {
            scanf("%d %d",&n,&m);
            a[f++]=m;
            if(n+m==0)break;
            vis[n]=1;vis[m]=1;
              fun(n,m);
        }
        sort(a,a+f);
        for(i=0;i<f-1;i++)
            if(a[i]==a[i+1])sign=1;//判断是否有多个箭头指向一个点！！！
        for(sum=0,j=1;j<100005;j++)
        {
            if(bin[j]==j&&vis[j])
                  sum++;
               if(sum>1){sign=1;break;}
        }
        if(sign)printf("Case %d is not a tree.\n",h);
        else printf("Case %d is a tree.\n",h);
        h++;
     }
     return 0;
 }