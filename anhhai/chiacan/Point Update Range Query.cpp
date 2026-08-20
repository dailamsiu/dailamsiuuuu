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
int n,q,a[N],k,sum[N];
int get_id(int pos)
{
    return (pos-1)/k+1;
}
int get_last(int pos)
{
    return min(n,pos*k);
}
int get_first(int pos)
{
    return get_last(pos-1)+1;
}
void solve() {
    cin>>n>>q;
    k=max(1LL,(int)sqrt(n));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[get_id(i)]+=a[i];
    }
    while(q--)
    {
        int t;cin>>t;
        if(t==1)
        {
            int l,r;cin>>l>>r;
            sum[get_id(l)]-=a[l];
            sum[get_id(l)]+=r;
            a[l]=r;
        }
        else
        {
            int l,r;cin>>l>>r;
            int ans=0;
            if(get_id(l)==get_id(r))    
            {
                for(int i=l;i<=r;i++)   ans+=a[i];
            }
            else
            {
                for(int i=l;i<=get_last(get_id(l));i++) ans+=a[i];
                for(int i=get_id(l)+1;i<=get_id(r)-1;i++)   ans+=sum[i];
                for(int i=get_first(get_id(r));i<=r;i++)    ans+=a[i];
            }
            cout<<ans<<'\n';
        }
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}