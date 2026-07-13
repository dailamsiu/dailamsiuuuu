#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define NAME "ten"
#define pii pair<int,int>
using namespace std;
int n;
main()
{
    if(fopen(NAME ".inp","r"))
    {
        freopen(NAME ".inp","r",stdin);
        freopen(NAME ".out","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    int k=sqrt(n);
    if(k*k>=n)
    {
        cout<<k<<' '<<k;

    }
    else if(k*(k+1)>=n)
    {
        cout<<k<<' '<<k+1;
    }
    else if((k+1)*(k+1)>=n)
    {
        cout<<k+1<<' '<<k+1;
    }
}
