#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define pii pair<int,int>
#define ten "cau"
using namespace std;
int n,a[N];
main()
{
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n;
    for(int i=1;i<=n;i++)  
    {
        int x;cin>>x;
        a[i]=a[i-1]+x;
    }
    int mx=-1e18;
    for(int i=1;i<=n;i++)
    {
        int l=a[i],r=a[n]-a[i];
        mx=max({mx,l*(-1)+r,l+r*(-1)});
    }
    cout<<mx;
}
