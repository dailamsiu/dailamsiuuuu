#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int n,x,c[N],dp[N];
main()
{
    cin>>n>>x;
    for(int i=1; i<=n; i++)   cin>>c[i];
    dp[0]=1;
    for(int j=0; j<=x; j++)
        for(int i=1; i<=n; i++)
        {

    if(j-c[i]>=0)
            dp[j]+=dp[j-c[i]];
            dp[j]%=mod;

        }
    cout<<dp[x];

}
