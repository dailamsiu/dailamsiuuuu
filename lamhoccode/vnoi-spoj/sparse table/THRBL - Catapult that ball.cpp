#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const int INF=1e18;
int n,m,h[N],sp[20][N];
int query(int l,int r)
{

    if(l>r) return 0;
    int k=__lg(r-l+1);
    return max(sp[k][l],sp[k][r-(1<<k)+1]);
}
main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
        sp[0][i]=h[i];
    }
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j+(1<<i)-1<=n;j++)
        {
            sp[i][j]=max(sp[i-1][j],sp[i-1][j+(1<<(i-1))]);
        }
    }
    int d=0;
    while(m--)
    {
        int x,y;cin>>x>>y;
        if(query(x+1,y-1)<=h[x]) d++;
    }
    cout<<d;
}
