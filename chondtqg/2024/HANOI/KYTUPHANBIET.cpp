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
int dem(int k)
{
    int distinct=0,ans=0;
    vector<int>mp(26,0);
    int l=1;
    for(int r=1;r<=s.size();r++)
    {
        mp[s[r-1]-'a']++;
        if(mp[s[r-1]-'a']==1)   distinct++;
        while(l<=s.size()&&distinct>k)
        {
            mp[s[l-1]-'a']--;
            if(mp[s[l-1]-'a']==0)   distinct--;
            l++;
        }
        ans+=r-l+1;
    }
    return ans;
}
void solve() {
    cin>>s;
    unordered_set<int>se;
    for(auto x:s)   se.insert(x);
    for(int nk=1;nk<=se.size();nk++)
    {
        cout<<dem(nk)-dem(nk-1)<<'\n';
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}