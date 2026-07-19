//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("inline")
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
int n,k;
struct node
{
    int a,b,c,cnt,ans;
}p[N],tmp[N];
int bit[N];
void upd(int pos,int val)
{
    for(;pos<=k;pos+=pos&-pos)
    {
        bit[pos]+=val;
    }
}
int get(int pos)
{
    int res=0;
    for(;pos>=1;pos-=pos&-pos)
    {
        res+=bit[pos];
    }
    return res;
}
void calc(int l,int r)
{
    if(l==r)    return;
    int mid=(l+r)/2;
    calc(l,mid);
    calc(mid+1,r);
    int i=l,j=mid+1,cur=l;
    while(j<=r)
    {
        while(i<=mid&&p[i].b<=p[j].b)
        {
            upd(p[i].c,p[i].cnt);i++;
        }
        p[j].ans+=get(p[j].c);
        j++;
    }
    FOR(t,l,i-1)
    {
        upd(p[t].c,-p[t].cnt);
    }
    i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(p[i].b<=p[j].b)  tmp[cur++]=p[i++];
        else    tmp[cur++]=p[j++];
    }
    while(i<=mid)   tmp[cur++]=p[i++];
    while(j<=r) tmp[cur++]=p[j++];
    FOR(i,l,r)  p[i]=tmp[i];
}
int m=0;
void solve() {
    cin>>n>>k;
    FOR(i,0,n-1)
    {
        cin>>tmp[i].a>>tmp[i].b>>tmp[i].c;
    }
    sort(tmp,tmp+n,[](node u,node v){
         if(u.a!=v.a)   return u.a<v.a;
         if(u.b!=v.b)   return u.b<v.b;
         return u.c<v.c;
         });
    for(int i=0;i<n;)
    {
        int j=i;
        while(j<n&&tmp[j].a==tmp[i].a&&tmp[j].b==tmp[i].b&&tmp[j].c==tmp[i].c)  j++;
        p[++m]=tmp[i];
        p[m].cnt=j-i;
        i=j;
    }
    calc(1,m);unordered_map<int,int>res;
    FOR(i,1,m)
    {
        res[p[i].ans+p[i].cnt-1]+=p[i].cnt;
    }
    FOR(i,0,n-1)
    {
        cout<<res[i]<<'\n';
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
