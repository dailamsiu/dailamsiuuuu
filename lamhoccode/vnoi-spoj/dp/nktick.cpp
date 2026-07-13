#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int n,t[N],r[N],dp[N];
/// dp[i] thoi gian phuc vu nho nhat khi phuc vu khach hang tu 1 den i
/// dp[1]=t[1] dp[2]=min(dp[i-1]+t[i],dp[i-2]+r[i])
main()
{
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>t[i];
    for(int i=2;i<=n;i++)   cin>>r[i];
    dp[1]=t[1];
    for(int i=2;i<=n;i++)
    {
        dp[i]=min(dp[i-1]+t[i],dp[i-2]+r[i]);
    }
    cout<<dp[n];


}
