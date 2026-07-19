#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,m,a[N],b[N],mn=1e18;
void siu()
{
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    unordered_map<int,int>mp;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=m; k++)
            {
                int cal=a[i]+a[j]-a[k];
                if(mp[cal]&&mp[cal]!=k&&i!=j)
                {
                    mn=min(mn,a[i]+a[j]);
                }
                mp[b[k]]=k;
            }
        }
    }

}
void suban()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            for(int x=1; x<=m; x++)
            {
                for(int y=x+1; y<=m; y++)
                {
                    if(a[i]+a[j]==b[x]+b[y])
                        mn=min(mn,a[i]+a[j]);
                }
            }
        }
    }
}
main()
{
    cin>>n>>m;

    for(int i=1; i<=n; i++)   cin>>a[i];
    for(int i=1; i<=m; i++)   cin>>b[i];
    if(n*(n-1)/2*m*(m-1)/2<=1e8) suban();
    else
        siu();

    if(mn==1e18)    cout<<"no volleyball today";
    else    cout<<mn;
}
/*
3 4
110 120 103
150 105 111 108
*/
