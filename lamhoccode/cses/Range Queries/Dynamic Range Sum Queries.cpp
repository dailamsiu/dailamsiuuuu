#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const int INF=1e18;
int n,q,a[N];
struct segmenttree
{
    int st[4*N];
    void build(int id,int l,int r)
    {
        if(l==r)
        {
            st[id]=a[l];return;
        }
        int mid=(l+r)/2;
        build(id*2,l,mid);build(id*2+1,mid+1,r);st[id]=st[id*2]+st[id*2+1];
    }
    void upd(int id,int l,int r,int pos,int val)
    {
        if(l==r)
        {
            a[pos]=val;
            st[id]=val;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid)    upd(id*2,l,mid,pos,val);
        else    upd(id*2+1,mid+1,r,pos,val);
        st[id]=st[id*2]+st[id*2+1];
    }
    int get(int id,int l,int r,int u,int v)
    {
        if(v<l||r<u)    return 0;
        if(u<=l&&r<=v)
        {
            return st[id];
        }
        int mid=(l+r)/2;
        return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
    }
};

segmenttree st;
main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)   cin>>a[i];
    st.build(1,1,n);
    for(int i=1;i<=q;i++)
    {
        int t,a,b;cin>>t>>a>>b;
        if(t==1)
            st.upd(1,1,n,a,b);
        else
            cout<<st.get(1,1,n,a,b)<<'\n';

    }
}
