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
int n;
struct node
{
    int x,y;
}a[N];
int eucliddistance(node i,node j)
{
    return sqrt((i.x-j.x)*(i.x-j.x)+(j.y-i.y)*(j.y-i.y));
}
bool checkthanghang(node i,node j,node k)
{
    return (j.x-i.x)*(k.y-i.y)-(j.y-i.y)*(k.x-i.x)==0;
}
bool check(int a,int b,int c)
{
    return (a+b>c&&b+c>a&&a+c>b);
}
int d=0;
unordered_map<int,int>mp;

void solve() {
    cin>>n;
    FOR(i,1,n)
    {
        cin>>a[i].x>>a[i].y;
    }
    FOR(i,1,n)
    {
        FOR(j,i+1,n)
        {
            FOR(k,j+1,n)
            {
                if(!checkthanghang(a[i],a[j],a[k]))
                {
                    mp[i]++,mp[j]++,mp[k]++;d++;
                }

            }
        }
    }
    cout<<d<<' ';
    int id=1;
    FOR(i,2,n)  if(mp[i]<mp[id])    id=i;
    cout<<id;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
