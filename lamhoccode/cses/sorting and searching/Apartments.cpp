#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int n,m,k,a[N],b[N];
main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=m;i++)   cin>>b[i];
    int i=1,j=1,ans=0;
    sort(a+1,a+n+1);sort(b+1,b+m+1);
    while(i<=n&&j<=m)
    {
        if(a[i]-k>b[j]) j++;
        else if(a[i]+k<b[j])   i++;
        else if(abs(a[i]-b[j])<=k)   ans++,i++,j++;
    }
    cout<<ans;

}
