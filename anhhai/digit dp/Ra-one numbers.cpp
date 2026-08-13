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
vector<int>num;
int dp[10][100][100][2];
int calc(int pos,int chan,int le,int tight)
{
    if(pos==num.size())
    {
        return (chan-le)==1;
    }
    if(dp[pos][chan][le][tight]!=-1)    return dp[pos][chan][le][tight];
    int lim=tight?num[pos]:9,res=0;
    for(int d=0;d<=lim;d++)
    {
        int nt=tight&&(d==lim);
        if((num.size()-pos)&1) res+=calc(pos+1,chan,le+d,nt);
        else    res+=calc(pos+1,chan+d,le,nt);
    }
    return dp[pos][chan][le][tight]=res;
}
int pre(int x)
{
    num.clear();
    if(x==0)    num.push_back(0);
    while(x>0)
    {
        num.push_back(x%10);
        x/=10;
    }
    reverse(num.begin(),num.end());
    memset(dp,-1,sizeof(dp));
    return calc(0,0,0,1);
}

void solve() {
    int l,r;cin>>l>>r;
    if(l!=0)    l--;
    cout<<pre(r)-pre(l)<<'\n';
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; cin >> ntest;
    while (ntest--) solve();
}