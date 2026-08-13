#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
const int N = 1e6 + 5;
const int mod = 1e9+7;
const int offset=2e5+5;
int n,a[N],bit[N];
void upd(int pos,int val)
{
    for(;pos<=N;pos+=pos&-pos)  bit[pos]+=val;
}
int get(int pos)
{
    int res=0;
    for(;pos>0;pos-=pos&-pos)   res+=bit[pos];
    return res;

}
int query(int l,int r)
{
    return get(r)-get(l-1);
}
int mnl[N],mxl[N],mnr[N],mxr[N];
int calc(int l,int r)
{
    if(l==r)
    {
        return 1;
    }
    int mid=(l+r)/2;
    int res=calc(l,mid)+calc(mid+1,r);
    mnl[mid]=mxl[mid]=a[mid];
    FORD(i,mid-1,l)
    {
        mnl[i]=min(mnl[i+1],a[i]);
        mxl[i]=max(mxl[i+1],a[i]);
    }
    mxr[mid+1]=mnr[mid+1]=a[mid+1];
    FOR(i,mid+2,r)
    {
        mnr[i]=min(mnr[i-1],a[i]);
        mxr[i]=max(mxr[i-1],a[i]);
    }
    int jmax=mid,jmin=mid;
    ///case 1: min max deu o ben trai=> mxl[i]-mnl[i]>=j-i
    FORD(i,mid,l)
    {
        while(jmax+1<=r&&mxr[jmax+1]<=mxl[i])   jmax++;
        while(jmin+1<=r&&mnr[jmin+1]>=mnl[i])   jmin++;
        int d=min(jmax,jmin);
        if(d>mid)
        {
            res+=max(0LL,min(d,mxl[i]-mnl[i]+i)-mid);
        }
    }
    jmax=jmin=mid+1;
    ///case 2: min max deu o ben phai=> mxr[i]-mnr[i]>=i-j
    FOR(i,mid+1,r)
    {
        while(jmax-1>=l&&mxl[jmax-1]<mxr[i])
        {
            jmax--;
        }
        while(jmin-1>=l&&mnl[jmin-1]>mnr[i])    jmin--;
        int d=max(jmin,jmax);
        if(d<=mid)
        {
            res+=max(0LL,mid-max(d,i-(mxr[i]-mnr[i]))+1);
        }
    }
    jmax=jmin=mid;
    ///case 3: max trai min phai=> mxl[i]-mnr[j]>=j-i
    FORD(i,mid,l)
    {
        while(jmax+1<=r&&mxr[jmax+1]<=mxl[i])
        {
            jmax++;
            if(jmax>jmin)   upd(mnr[jmax]+jmax,1);
        }
        while(jmin+1<=r&&mnr[jmin+1]>=mnl[i])
        {
            jmin++;
            if(jmax>=jmin)  upd(mnr[jmin]+jmin,-1);
        }
        if(jmin<jmax)
        {
            res+=query(1,mxl[i]+i);
        }
    }
    FOR(i,jmin+1,jmax)
    {
        upd(mnr[i]+i,-1);
    }
    jmax=jmin=mid;
    ///case 4: max phai min trai=> mxr[j]-j>=mnl[i]-i
    FORD(i,mid,l)
    {
        while(jmin+1<=r&&mnr[jmin+1]>=mnl[i])
        {
            jmin++;
            if(jmin>jmax)   upd(mxr[jmin]-jmin+offset,1);
        }
        while(jmax+1<=r&&mxr[jmax+1]<=mxl[i])
        {
            jmax++;
            if(jmin>=jmax)  upd(mxr[jmax]-jmax+offset,-1);
        }
        if(jmin>jmax)
        {
            res+=query(mnl[i]-i+offset,N);
        }
    }
    FOR(i,jmax+1,jmin)
        upd(mxr[i]-i+offset,-1);
        return res;

}
void solve() {
    cin>>n;
    FOR(i,1,n)
    {
        cin>>a[i];
    }
    cout<<calc(1,n);
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
