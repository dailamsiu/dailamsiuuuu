#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const int INF=1e18;
int n,q,a[N],st[4*N];
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=min(st[id*2],st[id*2+1]);
}
void upd(int id,int l,int r,int pos,int val)
{
    if(l==r)
    {
        st[id]=val;
        a[pos]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)upd(id*2,l,mid,pos,val);
    else    upd(id*2+1,mid+1,r,pos,val);
    st[id]=min(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v)
{
    if(v<l||r<u)    return 1e18;
    if(u<=l&&r<=v)  return st[id];
    int mid=(l+r)/2;
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)   cin>>a[i];
    build(1,1,n);
    while(q--)
    {
        int   t,pos,val;cin>>t>>pos>>val;
        if(t==1)    upd(1,1,n,pos,val);
        else    cout<<get(1,1,n,pos,val)<<'\n';
    }
}
