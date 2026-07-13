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
const int N = 1e3+5;
const int mod = 998244353;
const int BASE = 3137;
const int BLSZ=448;
///0:ngang 1:doc 2:cheochinh 3:cheophu
int n,xuoi[4][N][N],nguoc[4][N][N],b[N][N];
char a[N][N];
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]=='X')
            {
                xuoi[0][i][j]=xuoi[0][i][j-1]+1;
                xuoi[1][i][j]=xuoi[1][i-1][j]+1;
                xuoi[2][i][j]=xuoi[2][i-1][j-1]+1;
                xuoi[3][i][j]=xuoi[3][i-1][j+1]+1;
            }
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=n;j>=1;j--)
        {
            if(a[i][j]=='X')
            {
                nguoc[0][i][j]=nguoc[0][i][j+1]+1;
                nguoc[1][i][j]=nguoc[1][i+1][j]+1;
                nguoc[2][i][j]=nguoc[2][i+1][j+1]+1;
                nguoc[3][i][j]=nguoc[3][i+1][j-1]+1;
                for(int k=0;k<4;k++)
                {
                    b[i][j]=max(b[i][j],xuoi[k][i][j]+nguoc[k][i][j]-1);
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<b[i][j]<<' ';
        }
        cout<<'\n';
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
