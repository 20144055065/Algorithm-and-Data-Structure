 #include<iostream>
 #include<string.h>
 using namespace std;
 #include<map>
map<string,int>a;
int bin[200005];
int findx(int x)
 {
     int r=x;
     while(r!=bin[r])
        r=bin[r];
     return r;
 }
void fun(int x,int y,int h)
 {
   int tx,ty;
   tx=findx(x);
   ty=findx(y);
   if(tx!=ty&&!h)
        bin[tx]=ty;
   else
   {
         if(h==1)
        if(tx==ty)
           cout<<"yes\n";
           else cout<<"no\n";
   }
 }
int main()
{
    int t,h,i,s=1;
    string n,m;
    for(i=1;i<200005;i++)
        bin[i]=i;
    cin>>t;
    while(t--)
    {
        cin>>h>>n>>m;
         if(!a.count(n))//�ж������Ƿ��ظ����ֹ���
           a[n]=s++;
         if(!a.count(m))
            a[m]=s++;
            //����a[]�������ǰ��������α�ţ�
            fun(a[n],a[m],h);
    }
    return 0;
}