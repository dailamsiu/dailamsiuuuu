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
    int n,q,a[N];
    struct node
    {
        int sum,pre,suff,ans;
    }st[4*N];
    node combine(node left,node right)
    {
        node t;
        t.sum=left.sum+right.sum;
        t.pre=max(left.pre,left.sum+right.pre);
        t.suff=max(right.suff,right.sum+left.suff);
        t.ans=max({left.ans,right.ans,left.suff+right.pre});
        return t;
    }
    void build(int id,int l,int r)
    {
        if(l==r)
        {
            int x=max(0LL,a[l]);
            st[id]={a[l],x,x,x};
            return;
        }
        int mid=(l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        st[id]=combine(st[id*2],st[id*2+1]);
    }
    node get(int id,int l,int r,int u,int v)
    {
        if(v<l||r<u)    return {0,0,0,0};
        else if(u<=l&&r<=v) return st[id];
        int mid=(l+r)/2;
        node left=get(id*2,l,mid,u,v);
        node right=get(id*2+1,mid+1,r,u,v);
        return combine(left,right);
    }
    void solve() {
        cin>>n>>q;
        for(int i=1;i<=n;i++)   cin>>a[i];
        build(1,1,n);
        while(q--)
        {
            int a,b;cin>>a>>b;
            cout<<get(1,1,n,a,b).ans<<'\n';
        }
        
    }
    dailamsiu() {
        if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
        ios::sync_with_stdio(0); cin.tie(0);
        int ntest = 1; //cin >> ntest;
        while (ntest--) solve();
    }