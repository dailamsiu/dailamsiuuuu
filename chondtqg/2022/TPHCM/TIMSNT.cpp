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
const int N = 3e6 + 5;
const int mod = 1e9+7;
int snt[N];
vector<string>prime;
string translate(int x)
{
    string res="";
    while(x>0)
    {
        int d=x%10;
        res+=(d+'0');
        x/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}
void sang()
{
    snt[1]=snt[0]=1;
    for(int i=2;i*i<N;i++)
    {
        if(!snt[i])
        {
            for(int j=i*i;j<N;j+=i)
            {
                snt[j]=1;
            }
        }
    }
    for(int i=2;i<N;i++)
    {
        if(!snt[i]) prime.push_back(translate(i));
    }
}
string t;
string s;
void solve() {
    cin>>s;
    string last="";
    for(auto x:prime)
    {
        t+=x;
        last=x;
        if(t.size()>=s.size())  break;
    }
    if(t==s)    cout<<last;
    else    cout<<"-1";
}
dailamsiu() {
    sang();
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}