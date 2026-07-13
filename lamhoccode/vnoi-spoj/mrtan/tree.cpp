#include<bits/stdc++.h>
#define int long long
#define N 1000005
using namespace std;

int n,m,f[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;

        if(i%2==1)
        {
            f[1]++;
            f[x+1]--;
        }
        else
        {
            f[m-x]++;
            f[m+1]--;
        }
    }

    int cur=0,mn=1e18,ways=0;

    for(int i=1;i<=m;i++)
    {
        cur+=f[i];

        if(cur<mn)
        {
            mn=cur;
            ways=1;
        }
        else if(cur==mn)
        {
            ways++;
        }
    }

    cout<<mn<<" "<<ways;
}
