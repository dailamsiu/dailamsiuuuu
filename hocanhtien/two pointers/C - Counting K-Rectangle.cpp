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
const int N = 1e3 + 5;
const int mod = 1e9+7;
int m,n,k,dem[N],dem1[N];
char c[N][N];
int calc(int dem[])
{
    int res=0;
    for(int i=0;i<26;i++)   res+=(dem[i]>0);
    return res;
}
void solve() {
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++)   for(int j=1;j<=n;j++)   cin>>c[i][j];    
    int res=0;
    for(int r1=1;r1<=m;r1++)
    {
        for(int r2=r1;r2<=m;r2++)
        {
            for(int i=0;i<=25;i++)  dem[i]=dem1[i]=0;
            int l1=1,l2=1;
            for(int r=1;r<=n ;r++)
            {
                for(int j=r1;j<=r2;j++) dem[c[j][r]-'A']++,dem1[c[j][r]-'A']++;
                while(calc(dem)>k)
                {
                    for(int j=r1;j<=r2;j++) dem[c[j][l1]-'A']--;
                    l1++;
                }
                while(calc(dem1)>=k)
                {
                    for(int j=r1;j<=r2;j++) dem1[c[j][l2]-'A']--;
                    l2++;
                }
                res+=l2-l1;
            }
        }
        
    }
    cout<<res;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}