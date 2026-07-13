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
const int mod = 998244353;
const int BASE = 3137;
const int BLSZ=448;
int r,c,h,w,prer[N],prec[N];string row,col;
void solve() {
    cin>>r>>c>>h>>w>>row>>col;
    for(int i=1;i<=r;i++)
    {
        prer[i]=prer[i-1]+(row[i-1]=='0');
    }
    for(int i=1;i<=c;i++)
    {
        prec[i]=prec[i-1]+(col[i-1]=='0');
    }
    int xmin=LLONG_MAX,xmax=LLONG_MIN;
    for(int i=h;i<=r;i++)
    {
        int x=prer[i]-prer[i-h];
        xmin=min(xmin,x);
        xmax=max(xmax,x);
    }
    int ymin=LLONG_MAX,ymax=LLONG_MIN;
    for(int i=w;i<=c;i++)
    {
        int y=prec[i]-prec[i-w];
        ymin=min(ymin,y);
        ymax=max(ymax,y);
    }
    int ans=0;
    for(int x:{xmin,xmax})
        {
            for(int y:{ymin,ymax})
                {
                    ans=max(ans,x*y+(h-x)*(w-y));
                }
        }
        cout<<ans;

}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
