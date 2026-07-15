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
int n,m;
char a[N][N];
int dista[N][N],distm[N][N],trace[N][N];
int stx,sty;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
char direct[]={'D','R','U','L'};
bool check(int x,int y)
{
    return (x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]!='#');
}
void solve() {
    cin>>n>>m;
    queue<pii>M,A;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            dista[i][j]=distm[i][j]=1e18;trace[i][j]=-1;
            if(a[i][j]=='M')
            {
                distm[i][j]=1;M.push({i,j});
            }
            else if(a[i][j]=='A')
            {
                dista[i][j]=1;A.push({i,j});stx=i,sty=j;
            }
        }
    }
    while(M.size())
    {
        auto [x,y]=M.front();M.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(check(nx,ny)&&distm[nx][ny]==1e18)
            {
                distm[nx][ny]=distm[x][y]+1;
                M.push({nx,ny});
            }
        }
    }
    int endx=-1,endy=-1;
    while(A.size())
    {
        auto [x,y]=A.front();A.pop();
        if(x==1||x==n||y==1||y==m)
        {
            endx=x,endy=y;break;
        }
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(check(nx,ny)&&dista[nx][ny]==1e18&&dista[x][y]+1<distm[nx][ny])
            {
                dista[nx][ny]=dista[x][y]+1;
                trace[nx][ny]=i;
                A.push({nx,ny});
            }
        }
    }
    if(endx==-1)   
    {
        cout<<"NO";
        return;
    }
    cout<<"YES\n";
    string res="";
    while(endx!=stx||endy!=sty)
    {
        res+=direct[trace[endx][endy]];
        endy-=dy[trace[endx][endy]];
        endx-=dx[trace[endx][endy]];
    }
    reverse(res.begin(),res.end());
    cout<<res.size()<<'\n'<<res;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}