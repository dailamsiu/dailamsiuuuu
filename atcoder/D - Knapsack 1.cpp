#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int n,W,w[N],v[N],dp[105][100005];
main()
{
    cin>>n>>W;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j-w[i]>=0)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
            }

        }
    }
    cout<<dp[n][W];

}
