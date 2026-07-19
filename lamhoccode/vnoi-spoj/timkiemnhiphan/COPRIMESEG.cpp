#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int n,a[N],sp[20+1][N];
int get(int l,int r)
{
    int i=__lg(r-l+1);
    return __gcd(sp[i][l],sp[i][r-(1<<i)+1]);
}
bool check(int len)
{
    for(int i=1;i+len-1<=n;i++)
    {
        if(get(i,i+len-1)==1)  return 1;
    }
    return 0;
}
main()
{
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=n;i++)   sp[0][i]=a[i];
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j+(1<<i)-1<=n;j++)
        {
            sp[i][j]=__gcd(sp[i-1][j],sp[i-1][j+(1<<(i-1))]);
        }
    }
    int l=1,r=n,ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans;

}
