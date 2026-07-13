#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const int INF=1e18;
int n,q,x[N],sp[20][N];
int query(int l,int r)
{
    int k=__lg(r-l+1);
    return min(sp[k][l],sp[k][r-(1<<k)+1]);
}
main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];sp[0][i]=x[i];
    }
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j+(1<<i)-1<=n;j++)
        {
            sp[i][j]=min({sp[i-1][j],sp[i-1][j+(1<<(i-1))]});
        }
    }
    while(q--)
    {
        int a,b;cin>>a>>b;
        cout<<query(a,b)<<'\n';
    }
}
