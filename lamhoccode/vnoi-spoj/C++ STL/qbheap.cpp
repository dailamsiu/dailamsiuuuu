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
string s;
void solve() {
    priority_queue<int>q;
    while(cin>>s)
    {
        if(s[0]=='-')  
        {
            if(!q.empty())
            {
                q.pop();
            }
        }
        else
        {
            int d=0;
            for(int i=1;i<s.size();i++)
            {
                d=d*10+s[i]-48;
            }
            if(q.size()<15000)
            {
                q.push(d);
            }
        }
    }
    while(!q.empty())
    {
        cout<<q.top()<<'\n';q.pop();
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}