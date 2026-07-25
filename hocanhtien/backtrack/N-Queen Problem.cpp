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
int dd[20][20];
int n=8;
bool check(vector<int>&a)
{
    int d1[20]={0},d2[20]={0};
    for(int i=0;i<a.size();i++)
    {
        int x=i,y=a[i];
        int l=x-y+n,r=x+y;
        if(d1[l]||d2[r]||dd[x][y])  return 0;
        d1[l]=1,d2[r]=1;
    }
    return 1;
}
void solve() {
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            char c;cin>>c;
            if(c=='*')  dd[i][j]=1;
        }
    }
    vector<int>a;
    int ans=0;
    for(int i=0;i<8;i++)    a.push_back(i);
    do
    {
        ans+=check(a);
    } while (next_permutation(a.begin(),a.end()));
    cout<<ans;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}