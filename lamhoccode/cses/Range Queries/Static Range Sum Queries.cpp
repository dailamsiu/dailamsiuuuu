#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int n,a[N],q;
main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)   {
        int x;cin>>x;
        a[i]=a[i-1]+x;
    }
    while(q--)
    {
        int x,y;cin>>x>>y;
        cout<<a[y]-a[x-1]<<'\n';
    }
}
