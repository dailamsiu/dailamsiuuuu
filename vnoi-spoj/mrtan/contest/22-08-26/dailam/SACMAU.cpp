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
#define task "SACMAU"
#define dailamsiu main
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) { assert(l <= r); return uniform_int_distribution<int>(l, r)(rd); }
const int N = 2e5 + 5;
const int mod = 1e9+7;
int n,q,a[N],l[N],r[N],ans[N],pre[35][N],s2=1,s3=1,cnt[N];
void sub1()
{
    for(int i=1;i<=q;i++)
    {
        for(int j=l[i];j<=r[i];j++)
        {
            cnt[a[j]]++;
        }
        int d=0;
        for(int j=l[i];j<=r[i];j++)
        {
            if(cnt[a[j]]==1)
            {
                d++;
                cnt[a[j]]=0;
            }
        }
        for(int j=l[i];j<=r[i];j++)
        {
            cnt[a[j]]=0;
        }
        cout<<d<<'\n';
    }
}
void sub2()
{
    int cur=0;
    for(int r=1;r<=n;r++)
    {
        if(cnt[a[r]]==0)    cur++;
        else if(cnt[a[r]]==1)   cur--;
        cnt[a[r]]++;
        ans[r]=cur;
    }
    for(int i=1;i<=q;i++)
    {
        cout<<ans[r[i]]<<'\n';
    }
}
void sub3()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=30;j++)
        {
            pre[j][i]=pre[j][i-1];
        }
        pre[a[i]][i]++;
    }
    for(int i=1;i<=q;i++)
    {
        int d=0;
        for(int j=1;j<=30;j++)
        {
            if(pre[j][r[i]]-pre[j][l[i]-1]==1)  d++;
        }
        cout<<d<<'\n';
    }
}
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>30) s3=0;
    }
    cin>>q;
    for(int i=1;i<=q;i++)   
    {
        cin>>l[i]>>r[i];
        if(l[i]!=1) s2=0;
    }
    
     if(s2) sub2();
    else if(s3) sub3();
    else if(n<=2000&&q<=2000) sub1();
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}