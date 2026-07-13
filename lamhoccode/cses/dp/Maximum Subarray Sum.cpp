#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int n,x[N],dp[N];
main()
{
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>x[i];
    dp[1]=x[1];
    for(int i=1;i<=n;i++)
    {
        dp[i]=max(dp[i-1]+x[i],x[i]);
    }
    cout<<*max_element(dp+1,dp+n+1);

}
