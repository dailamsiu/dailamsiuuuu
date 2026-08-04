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
 int t,f[N];
 void solve() {
    cin>>t;
    f[1]=1;
    for(int i=2;i<=19;i++)
    {
        f[i]=f[i-1]*i;
    }
    while(t--)
    {
        int ans=1e18;
        int n;cin>>n;
        for(int mask=0;mask<(1<<16);mask++)
        {
            int s=0;
            for(int j=0;j<16;j++)
            {
                if(bit(mask,j))
                {
                    s+=f[j+1];
                }
            }
            int x=n-s;
            ans=min(ans,(int)__builtin_popcountll(x)+__builtin_popcountll(mask));
        }
        cout<<(ans==1e18?-1:ans)<<'\n';
    }
 }
 dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
 }