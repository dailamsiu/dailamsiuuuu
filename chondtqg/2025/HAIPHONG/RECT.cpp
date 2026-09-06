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
int n;
unordered_map<int,vector<int>>ox,oy;
int countrange(vector<int>&v,int s1,int s2)
{
    return upper_bound(v.begin(),v.end(),s2)-lower_bound(v.begin(),v.end(),s1);
}
int countpoint(int x,int y)
{
    if(ox.find(x)==ox.end())    return 0;
    return countrange(ox[x],y,y);
}
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;cin>>x>>y;
        ox[x].push_back(y);
        oy[y].push_back(x);
    }
    for(auto& o:ox)
    {
        sort(o.second.begin(),o.second.end());
    }
    for(auto& o:oy)
    {
        sort(o.second.begin(),o.second.end());
    }
    int m;cin>>m;
    while(m--)
    {
        int u1,v1,u2,v2;
        cin>>u1>>v1>>u2>>v2;
        if(u1==u2&&v1==v2)
        {
            cout<<countpoint(u1,v1);
        }
        else if(u1==u2||v1==v2)
        {
            if(u1==u2)
            {
                cout<< countrange(ox[u1],v1,v2);
            }
            else
            {
                cout<< countrange(oy[v1],u1,u2);
            }
        }
        else
        {
            int canhtren=countrange(oy[v2],u1,u2);
            int canhduoi=countrange(oy[v1],u1,u2);
            int canhphai=countrange(ox[u1],v1,v2);
            int canhtrai=countrange(ox[u2],v1,v2);
            cout<<canhtrai+canhduoi+canhtren+canhphai-countpoint(u1,v1)-countpoint(u2,v2)-countpoint(u1,v2)-countpoint(u2,v1);
        }
        cout<<'\n';
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}