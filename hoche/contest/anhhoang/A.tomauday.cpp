///y tuong:a[i]/a[j]=p(snt) => a[i]=p*a[j] => tong thua so nto a[i]>a[j] => dem xem moi so co bao nhieu thua so nguyen to co ca lap lai
///=>neu thua so nguyen to le thi in ra 1 chan thi in ra 2
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ten "cau"
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int n,a[N];
int spf[N],f[N];
void sang()
{
    for(int i=1;i<N;i++)
    {
        spf[i]=i;
    }
    for(int i=2;i*i<N;i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<N;j+=i)
            {
                if(spf[j]==j)spf[j]=i;
            }
        }
    }
    f[1]=0;
    for(int i=2;i<N;i++)
    {
        f[i]=f[i/spf[i]]+1;
    }
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    sang();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(f[a[i]]&1)   cout<<1<<' ';
        else    cout<<2<<' ';
    }

}
