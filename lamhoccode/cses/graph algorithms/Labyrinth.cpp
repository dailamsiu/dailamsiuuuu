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
int n,m,ia,ib,ja,jb,vis[N][N];
char a[N][N],trace[N][N];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='A')
            {
                ia=i,ja=j;
            }
            if(a[i][j]=='B')
            {
                ib=i,jb=j;
            }
        }
    }
    queue<pii>q;
    vis[ia][ja]=1;
    q.push({ia,ja});
    int dd=0;
    while(q.size())
    {
        auto [x,y]=q.front();q.pop();if(dd) break;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!vis[nx][ny]&&a[nx][ny]!='#')
            {
                if(i==0)    trace[nx][ny]='D';
                if(i==1)    trace[nx][ny]='R';
                if(i==2)    trace[nx][ny]='U';
                if(i==3)    trace[nx][ny]='L';
                vis[nx][ny]=1;
                q.push({nx,ny});
                if(nx==ib&&ny==jb)
                {
                    dd=1;break;
                }
            }
        }
    }
    if(!dd)
    {
        cout<<"NO";return;
    }
    cout<<"YES\n";
    string s="";
    while(ib!=ia||jb!=ja)
    {s+=trace[ib][jb];
        if(trace[ib][jb]=='D')  ib--;
        else if(trace[ib][jb]=='R')  jb--;
        else if(trace[ib][jb]=='L')  jb++;
        else if(trace[ib][jb]=='U')  ib++;
        
    }
    reverse(s.begin(),s.end());
    cout<<s.size()<<'\n'<<s;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}