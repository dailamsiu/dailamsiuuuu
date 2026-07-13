#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ten "cau"
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int len(int n)
{
    if(n==0||n==1)    return 1;
    return 2*len(n/2)+1;
}
int calc(int l,int r,int i,int j,int n)
{
    if(i>j||l>j||r<i) return 0;
    if(l<=i&&i<=j&&j<=r)    return n;
    int k=(i+j)/2;
    return calc(l,r,i,k-1,n/2)+(n%2&&l<=k&&k<=r)+calc(l,r,k+1,j,n/2);
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    int l,r,n;cin>>n>>l>>r;
    cout<<calc(l,r,1,len(n),n);
}
