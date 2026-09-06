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
int x,y;
string s,bestres;
bool check(int pos,int big,int cntx,int cnty,string &cur)
{
    if(pos==(int)s.size())
    {
        if(cntx==0&&cnty==0)
        {
            bestres=cur;return 1;
        }
        return 0;
    }
    vector<int>temp={x,y};
    for(auto t:temp)
    {
        if(pos==0&&t==0)    continue;
        if(t==x&&cntx==0)   continue;
        if(t==y&&cnty==0)   continue;
        if(!big&&t<(s[pos]-'0'))    continue;
        cur.push_back(t+'0');
        if(check(pos+1,big||(t>s[pos]-'0'),cntx-(t==x?1:0),cnty-(t==y?1:0),cur))    return 1;
        cur.pop_back();
    }
    return 0;
}
string createlen(int len)
{
    int half=len/2;
    string res="";
    if(x==0)
    {
        res+=(char)(y+'0');
        res+=string(half,x+'0');
        res+=string(half-1,y+'0');
    }
    else
    {
        res+=string(half,x+'0');
        res+=string(half,y+'0');
    }
    return res;
}
void solve() {
    cin>>s>>x>>y;
    if(x>y) swap(x,y);
    if(s.size()&1)
    {
        cout<<createlen(s.size()+1);
    }
    else
    {
        string cur="";
        if(check(0,0,s.size()/2,s.size()/2,cur))        
        {
            cout<<bestres;
        }
        else
        {
            cout<<createlen(s.size()+2);
        }
    }
    cout<<'\n';
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; cin >> ntest;
    while (ntest--) solve();
}