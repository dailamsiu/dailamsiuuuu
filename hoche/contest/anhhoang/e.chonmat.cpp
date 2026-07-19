#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ten "cau"
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int n,k,m,mask[N],d,cnt[N];
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int x;cin>>x;
            mask[x]^=(1<<i);
        }
    }
    for(int x=1;x<=m;x++)
    {
        cnt[mask[x]]++;
    }
    int thieu=m;
    for(int i=0;i<(1<<n);i++)
    {
        thieu=min(thieu,cnt[i]);
    }
    cout<<m-thieu;
}
