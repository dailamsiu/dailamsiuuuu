#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define pii pair<int,int>
#define ten "cau"
using namespace std;
int n,d[505][505],x[N],dd[N];
main()
{
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>d[i][j];
        }
    }
    for(int i=1;i<=n;i++)cin>>x[i];
    vector<int>ans;
    for(int i=n;i>=1;i--)
    {
        int k=x[i];
        dd[k]=1;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(d[i][k]+d[k][j]<d[i][j])
                {
                    d[i][j]=d[i][k]+d[k][j];
                }
                if(dd[i]&&dd[j])
                {
                    sum+=d[i][j];
                }
            }
        }ans.push_back(sum);
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans) cout<<x<<' ';
}
