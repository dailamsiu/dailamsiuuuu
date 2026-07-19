#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ten "cau"
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int n,x;
vector<int>sol[21];
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n>>x   ;
    sol[1]={0,1};
    for(int k=2;k<=n;k++)
    {
        sol[k]=sol[k-1];
        for(int i=(1<<(k-1))-1;i>=0;i--)
        {
            sol[k].push_back(sol[k-1][i]+(1<<(k-1)));
        }
    }
    for(int i=0;i<(1<<n);i++)
    {
        if(sol[n][i]==x)
        {
            for(int j=1;j<(1<<n);j++)
            {
                cout<<sol[n][(i+j)%(1<<n)]<<'\n';
            }
            break;
        }
    }
}
