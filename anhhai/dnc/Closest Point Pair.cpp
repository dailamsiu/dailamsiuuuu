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
struct node
{
    int x,y,id;
}p[N],tmp[N],st[N];
ld res=1e100;
int besta=-1,bestb=-1,n;
ld getdist(node a,node b)
{
        int dx=a.x-b.x,dy=a.y-b.y;
        return sqrt((ld)dx*dx+(ld)dy*dy);
}
void upd(node a,node b)
{
    ld d=getdist(a,b);
    int u=min(a.id,b.id),v=max(a.id,b.id);
    if(d<res-1e-12)
    {
        res=d;besta=u,bestb=v;
    }
    else if(fabs(d-res)<1e-12)
    {
        if(u<besta||(u==besta&&v<bestb))
        {
            besta=u;bestb=v;
        }
    }
}
void calc(int l,int r)
{
    if(r-l<=3)
    {
        for(int i=l;i<=r;i++)
        {
            for(int j=i+1;j<=r;j++) upd(p[i],p[j]);
        }
        sort(p+l,p+r+1,[](node a,node b){
             return a.y<b.y;
             });
             return;
    }
    int mid=(l+r)/2,midx=p[mid].x;
    calc(l,mid);
    calc(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r)
    {
        if(p[i].y<p[j].y)
            tmp[k++]=p[i++];
        else
            tmp[k++]=p[j++];
    }
    while(i<=mid)
        tmp[k++]=p[i++];
    while(j<=r)
        tmp[k++]=p[j++];
    for(int i=l;i<=r;i++)   p[i]=tmp[i];
    int m=0;
    for(int i=l;i<=r;i++)
    {
        if(fabs((ld)p[i].x-midx)<res)   st[m++]=p[i];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            if((ld)(st[j].y-st[i].y)>=res)
                break;
            upd(st[i],st[j]);
        }
    }

}
void solve() {
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].x>>p[i].y;
        p[i].id=i;
    }
    sort(p,p+n,[](node a,node b)
         {
             if(a.x!=b.x)   return a.x<b.x;
             return a.y<b.y;
         });
    calc(0,n-1);
    cout<<besta<<' '<<bestb<<fixed<<setprecision(6)<<' '<<res<<'\n';
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
