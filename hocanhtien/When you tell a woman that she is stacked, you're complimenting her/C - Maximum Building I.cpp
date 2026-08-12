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
const int N = 1e3 + 5;
const int mod = 1e9+7;
int n,m;

void solve() {
    cin>>n>>m;
    int kq=0;
    vector<int>temp(m+1,0);
    for(int i=1;i<=n;i++)
    {
        vector<int>h=temp;
        for(int j=1;j<=m;j++)
        {
            char x;cin>>x;
            if(x=='.')  h[j]++;
            else    h[j]=0;
        }
        temp=h;
        vector<int>l(m+1,0),r(m+1,0);
        for(int j=1;j<=m;j++)
        {
            l[j]=0,r[j]=m+1;
        }
        stack<int>stl;
        for(int j=m;j>=1;j--)
        {
            while(!stl.empty()&&h[stl.top()]>h[j])
            {
                l[stl.top()]=j;
                stl.pop();
            }
            stl.push(j);
        }
        stack<int>str;
        for(int j=1;j<=m;j++)
        {
            while(!str.empty()&&h[str.top()]>h[j])
            {
                r[str.top()]=j;str.pop();
            }
            str.push(j);
        }
        int ans=0;
        for(int j=1;j<=m;j++)
        {
            ans=max(ans,h[j]*(r[j]-l[j]-1));
        }
        kq=max(kq,ans);
    }
    cout<<kq;

}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}