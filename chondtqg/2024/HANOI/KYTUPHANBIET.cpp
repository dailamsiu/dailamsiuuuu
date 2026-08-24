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
int ans[N];
int calc(int k)
{   
    int mp[256];
    memset(mp,0,sizeof(mp));
    int l=0,distinct=0,ans=0;
    for(int r=0;r<s.size();r++)
    {
        mp[s[r]]++;
        if(mp[s[r]]==1) distinct++;
        while(l<s.size()&&distinct>k)
        {
            mp[s[l]]--;
            if(mp[s[l]]==0)
            {
                distinct--;
            }    
            l++;
        }
        ans+=r-l+1;
    }
    return ans;
    

}
void solve() {
    cin>>s;
    unordered_set<char>se;
    for(auto x:s)   se.insert(x);
    for(int k=1;k<=se.size();k++)
    {
        cout<<calc(k)-calc(k-1)<<'\n';
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}