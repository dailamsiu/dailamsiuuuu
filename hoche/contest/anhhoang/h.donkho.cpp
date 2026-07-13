#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ten "cau"
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int n,w[N],m,k[N],t[N],pre[N],ans;
int maxt[N];///maxt[c]=tai trong lon nhat trong so cac xe   co suc chua >=c

main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        pre[i]=pre[i-1]+w[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>k[i];

    }for(int i=1;i<=m;i++)
    {
        cin>>t[i];
        maxt[k[i]]=max(maxt[k[i]],t[i]);
    }
    for(int c=n-1;c>=1;c--)
    {
        maxt[c]=max(maxt[c],maxt[c+1]);
    }
    int i=1;
    while(i<=n)
    {
        int l=1,r=n-i+1,c=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(pre[i+mid-1]-pre[i-1]<=maxt[mid])
            {
                c=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        i+=c;
        ans++;
    }
    cout<<ans;

}
