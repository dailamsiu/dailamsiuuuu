#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ten "cau"
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int n,a[N];
int val(int x)
{
    int ans=0;
    for(int i=0;i<=30;i++)
    {
        ans=ans*2+((x>>i)&1);
    }
    return ans;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    int t;cin>>t;
    while(t--)
    {
            cin>>n;
    vector<pii>v;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        v.push_back({val(a[i]),i});
    }
    sort(v.begin(),v.end());
    for(auto [o,id]:v)  cout<<id<<' ';
    cout<<'\n';
    }

}
