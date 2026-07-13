#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const int INF=1e18;
int n,q,a[N];
main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        a[i]=a[i-1]^x;
    }
    while(q--)
    {
        int l,r;cin>>l>>r;
        cout<<(a[r]^a[l-1])<<'\n';
    }

}
