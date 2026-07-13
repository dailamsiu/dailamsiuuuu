#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ten "cau"
using namespace std;
const int N=20;
const int mod=1e9+7;
int n,f[N+1][N+1][N+1][N+1],a[N],res[N],k;

int calc(int i,int vmin1,int vmin2,int vmax)
{
    if(i>n)
    {
        return (vmin1+vmin2>vmax);
    }
    if(f[i][vmin1][vmin2][vmax]!=-1)return f[i][vmin1][vmin2][vmax];
    int cnt=0;
    for(int v=1;v<=n;v++)
    {
        int nvmin1,nvmin2,nvmax=max(vmax,v);
        if(v<vmin1)
        {
            nvmin1=v;
            nvmin2=vmin1;
        }
        else
        {
            nvmin1=vmin1;
            nvmin2=min(vmin2,v);
        }
        cnt+=calc(i+1,nvmin1,nvmin2,nvmax);
    }
    return f[i][vmin1][vmin2][vmax]=cnt;
}

void get1(int i,int vmin1,int vmin2,int vmax)
{
    if(i>n)
    {
        return;
    }
    for(int v=1;v<=n;v++)
    {
        int nvmin1,nvmin2,nvmax=max(vmax,v);
        if(v<vmin1)
        {
            nvmin1=v;
            nvmin2=vmin1;
        }
        else
        {
            nvmin1=vmin1;
            nvmin2=min(vmin2,v);
        }
        if(k>calc(i+1,nvmin1,nvmin2,nvmax))
        {
            k-=calc(i+1,nvmin1,nvmin2,nvmax);
        }
        else
        {
            res[i]=v;
            get1(i+1,nvmin1,nvmin2,nvmax);break;
        }
    }
}

int get2(int i,int vmin1,int vmin2,int vmax)
{
    if(i>n)
    {
        return 0;
    }
    int d=0;
    for(int v=1;v<a[i];v++)
    {
        int nvmin1,nvmin2,nvmax=max(vmax,v);
        if(v<vmin1)
        {
            nvmin1=v;
            nvmin2=vmin1;
        }
        else
        {
            nvmin1=vmin1;
            nvmin2=min(vmin2,v);
        }
        d+=calc(i+1,nvmin1,nvmin2,nvmax);
    }
    int v=a[i];int nvmin1,nvmin2,nvmax=max(vmax,v);
    if(v<vmin1)
        {
            nvmin1=v;
            nvmin2=vmin1;
        }
        else
        {
            nvmin1=vmin1;
            nvmin2=min(vmin2,v);
        }
        return d+get2(i+1,nvmin1,nvmin2,nvmax);
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n>>k;
    memset(f,-1,sizeof(f));
    cout<<calc(1,20,20,0)<<'\n';
    for(int i=1;i<=n;i++)cin>>a[i];
    get1(1,20,20,0);
    for(int i=1;i<=n;i++)cout<<res[i]<<' ';
    cout<<'\n';
    cout<<1+get2(1,20,20,0);
}
