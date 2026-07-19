#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[25],d;
void gen(int cur,int pos)
{
    if(d)   return ;
    if(cur==k)
    {
        d=1; return;
    }
 if(cur>k||pos>n)
    {
        return;
    }
    gen(cur+a[pos],pos+1);
    gen(cur,pos+1);
}
main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)   cin>>a[i];
    gen(0,1);
    if(d==1)    cout<<"YES";
    else    cout<<"NO";
}
