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
int n,m;
unordered_map<int,vector<int>>ox,oy;
int count_range(vector<int>&v ,int l,int r)
{
    return upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l);
}
int count_point(int x,int y)
{
    if(ox.find(x)==ox.end())    return 0;
    return count_range(ox[x],y,y);
}
void solve() {
    
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;cin>>a>>b;
        ox[a].push_back(b);
        oy[b].push_back(a);
    }
    for(auto& x:ox)
    {
        sort(x.second.begin(),x.second.end());
    }
    for(auto& y:oy)
    {
        sort(y.second.begin(),y.second.end());
    }
    cin>>m;
    while(m--)
    {
        int u1,v1,u2,v2;cin>>u1>>v1>>u2>>v2;
        if(u1==u2&&v1==v2)
        {
            cout<<count_point(u1,v1)<<'\n';
        }
        else if(u1==u2||v1==v2)
        {
            if(u1==u2)
            {
                cout<<count_range(ox[u1],v1,v2);
            }
            else 
            {
                cout<<count_range(oy[v1],u1,u2);
            }
            cout<<'\n';
        }
        else
        {
            int canhtren=count_range(oy[v2],u1,u2);
            int canhtrai=count_range(ox[u1],v1,v2);
            int canhphai=count_range(ox[u2],v1,v2);
            int canhduoi=count_range(oy[v1],u1,u2);
            cout<<canhtrai+canhtren+canhphai+canhduoi-count_point(u1,v1)-count_point(u2,v2)-count_point(u1,v2)-count_point(u2,v1)<<'\n';
        }
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}
