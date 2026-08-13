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
int n,l,r,bit[N],a[N];int sz=0;
void upd(int pos,int val)
{
    for(;pos<=sz;pos+=pos&-pos)
    {
        bit[pos]+=val;
    }
}
int get(int pos)
{
    int res=0;
    for(;pos>0;pos-=pos&-pos)
    {
        res+=bit[pos];
    }
    return res;
}
void solve() {
    cin>>n>>l>>r;
    vector<int>val;val.pb(0);
    for(int i=1;i<=n;i++)   
    {
        int x;cin>>x;
        a[i]=a[i-1]+x;
        val.push_back(a[i]);
        val.pb(a[i]-l);val.pb(a[i]-r);val.pb(a[i]+l);val.pb(a[i]+r);
    }
    sz=val.size();
    sort(val.begin(),val.end());
    val.erase(unique(val.begin(),val.end()),val.end());
    auto get_id = [&](int v) {
        return lower_bound(val.begin(),val.end(),v)-val.begin()+1;
    };
    upd(get_id(a[0]),1);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int left=get_id(a[i]-r),right=get_id(a[i]-l);  res+=get(right)-get(left-1);
        left=get_id(a[i]+l),right=get_id(a[i]+r);res+=get(right)-get(left-1);
        if(l==0)
        {
            res-=get(get_id(a[i])-get_id(a[i]-1));
        }
        upd(get_id(a[i]),1);
    }
    cout<<res;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}