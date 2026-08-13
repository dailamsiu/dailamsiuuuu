#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
#define bit(x, i) ((x >> i) & 1)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define task "test"
#define dailamsiu main
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) { assert(l <= r); return uniform_int_distribution<int>(l, r)(rd); }
const int N = 2e5 + 5;
const int mod = 998244353;
const int BASE = 3137;
const int BLSZ=448;
const int INF=1e18;
int n,m,barcode[N],pos[N];
struct node
{
    int minpos,maxpos;
}st[4*N];
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id]={pos[l],pos[l]};
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id].minpos=min(st[id*2].minpos,st[id*2+1].minpos);
    st[id].maxpos=max(st[id*2].maxpos,st[id*2+1].maxpos);
}
void upd(int id,int l,int r,int position,int value)
{
    if(l==r)
    {
        st[id]={value,value};
        return;
    }
    int mid=(l+r)/2;
    if(position<=mid)   upd(id*2,l,mid,position,value);
    else
            upd(id*2+1,mid+1,r,position,value);
    st[id].minpos=min(st[id*2].minpos,st[id*2+1].minpos);
    st[id].maxpos=max(st[id*2].maxpos,st[id*2+1].maxpos);
}
node get(int id,int l,int r,int u,int v)
{
    if(u>r||v<l)
    {
        return {INF,-INF};
    }
    if(u<=l&&r<=v)  return st[id];
    int mid=(l+r)/2;
    node left=get(id*2,l,mid,u,v),right=get(id*2+1,mid+1,r,u,v);
    return {min(left.minpos,right.minpos),max(left.maxpos,right.maxpos)};
}
void solve() {
    cin>>n>>m;
    FOR(i,1,n)
    {
        cin>>barcode[i];
        pos[barcode[i]]=i;
    }
    build(1,1,n);
    FOR(i,1,m)
    {
        int t,l,r;cin>>t>>l>>r;
        if(t==1)
        {
            int x=barcode[l],y=barcode[r];
            swap(barcode[l],barcode[r]);
            swap(pos[x],pos[y]);
            upd(1,1,n,x,pos[x]);
            upd(1,1,n,y,pos[y]);
        }
        else
        {
            node que=get(1,1,n,l,r);
            if(que.maxpos-que.minpos==r-l)
            {
                cout<<"YES\n";
            }
            else
            {
                cout<<"NO\n";
            }
        }
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
