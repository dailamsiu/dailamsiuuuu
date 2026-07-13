#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define pii pair<int,int>
#define ten "bai1"
using namespace std;
int n,a[N];
void sub1()
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ans=max(ans,max(a[j],a[i])%min(a[i],a[j]));
        }
    }
    cout<<ans;
}
void sub2()
{
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        for(int j=2*x;j<=a[n]+x;j+=x)
        {
            auto it=lower_bound(a+1,a+n+1,j);
            if(it==a+1)   continue;
            it--;
            if(*it>=j-x)
                ans=max(ans,*it-j+x);
        }
    }
    cout<<ans;
}
main()
{
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i];
    if(n<=5000)sub1();
    else    sub2();
}
