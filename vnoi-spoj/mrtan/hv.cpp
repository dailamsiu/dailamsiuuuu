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
int n,k,a[N],p,fact[N];
void query1(int a[])
{
    int cnt=1;
    vector<int>dd(n+1,0);
    FOR(i,1,n)
    {
        dd[a[i-1]]=1;
        for(int x=1; x<a[i-1]; x++)    if(!dd[x])  cnt+=fact[n-i];

    }
    cout<<cnt<<'\n';
}
void query2(int p)
{
    vector<int>dd(n+1,0);

    FOR(i,1,n)
    {
        FOR(x,1,n)
        {
            if(!dd[x])
            {
                if(fact[n-i]<p)   p-=fact[n-i];
                else
                {
                    cout<<x<<' ';
                    dd[x]=1;
                    break;
                }
            }
        }
    }
    cout<<'\n';
}
void solve() {
    cin>>n;
    fact[0]=1;
    for(int i=1;i<=n;i++)   fact[i]=fact[i-1]*i;
    cout<<fact[n]<<'\n';
    string s;
    cin.ignore();
    while(getline(cin,s))
    {
        if(s[0]=='1')

        {
            int d=0,x=0;
            for(int i=2;i<s.size();i++)
            {
                if(isdigit(s[i]))
                {
                    d=d*10+s[i]-48;
                }
                else
                {
                    a[x++]=d;
                    d=0;
                }
            }
            if(d) a[x++]=d;
            query1(a);
        }
        else
        {
            int p=0;
            for(int i=2;i<s.size();i++)
            {
                if(isdigit(s[i]))
                {
                    p=p*10+s[i]-48;
                }
            }
            query2(p);
        }
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
