#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define ft(v,d,n,x) for(int v=d;v<=n;v+=x)
#define fn(v,d,n,x) for(int v=d;v>=n;v-=x)
#define pii pair<int,int>
#define NAME "raumuong"
using namespace std;
int n,m,f[N];
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(NAME".inp","r"))
    {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        if(i%2==1)
        {
            f[1]++;
            f[x+1]--;
        }
        else
        {
            f[m-x+1]++;
            f[m+1]--;
        }
    }
    int cur=0,mn=1e18,cnt=0;
    for(int i=1;i<=m;i++)
    {
        cnt+=f[i];
        if(cnt<mn)
        {
            mn=cnt;cur=1;
        }
        else if(cnt==mn)
        {
            cur++;
        }
    }
    cout<<mn<<' '<<cur;

}
