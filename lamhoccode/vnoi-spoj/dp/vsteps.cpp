#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e6+5;
const int mod=14062008;
int n,k,dp[N],dd[N];
/// dp[i] so cach leo i cau thang
/// dp[1]=1
/// dd[i]=> dp[i]=0
/// !dd[i]=>dp[i]=(dp[i-1]+dp[i-2])%mod;
main()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        int x;cin>>x;
        dd[x]=1;
    }dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(dd[i])   dp[i]=0;
        else    dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    cout<<dp[n];

}
