#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const int INF=1e18;
int n,a[N],q,sp[20][N];
main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sp[0][i]=a[i];
    }
    cin>>q;
    while(q--)
    {
        int x;cin>>x;
        int l=1,r=1e5,ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid))
            {
                ans=mid;
                l=mid
            }
        }
    }

}
