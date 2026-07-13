#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define pii pair<int,int>
#define ten "cau"
using namespace std;
int n,k,q,a[N],cnt[5005][5005],dp[N];
const int mod=1e9+7;
main()
{
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cnt[i][0]=1;
    }
    for(int t=1;t<=k;t++)
    {
        for(int i=1;i<=n;i++)
        {
            cnt[i][t]=(cnt[i-1][t-1]+cnt[i+1][t-1])%mod;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int t=0;t<=k;t++)
        {
            dp[i]=(dp[i]+(cnt[i][t]*cnt[i][k-t])%mod)%mod;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+(a[i]*dp[i])%mod)%mod;
    }
    while(q--)
    {
        int i,x;cin>>i>>x;
        int d=(x-a[i]+mod)%mod;
        ans=(ans+(d*dp[i])%mod)%mod;
        a[i]=x;
        cout<<ans<<'\n';
    }
}
