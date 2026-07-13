///cach 1: dequy
//#include<bits/stdc++.h>
//#define int long long
//#define ld long double
//#define pb push_back
//#define pii pair<int, int>
//#define fi first
//#define se second
//#define bit(x, i) ((x >> i) & 1)
//#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
//#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
//#define task "test"
//#define dailamsiu main
//using namespace std;
//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
//int rand(int l, int r)
//{
//    assert(l <= r);
//    return uniform_int_distribution<int>(l, r)(rd);
//}
//const int N = 1e6 + 5;
//const int mod = 998244353;
//const int BASE = 3137;
//const int BLSZ=448;
//int s1,s2,s3;
//unordered_map<int,int>mp;
///pos la xuc xac thu pos co mat la so may
//void dequy(int pos,int sum)
//{
//    if(pos==4)
//    {
//        mp[sum]++;
//        return;
//    }
//    int lim;
//    if(pos==1)  lim=s1;
//    if(pos==2)  lim=s2;
//    if(pos==3)  lim=s3;
//    for(int dots=1;dots<=lim;dots++)
//    {
//        dequy(pos+1,dots+sum);
//    }
//
//}
//void solve()
//{
//    cin>>s1>>s2>>s3;
//    dequy(1,0);
//    int maxfreqsum=0,minsum=1e18;
//    for(int i=3;i<=s1+s2+s3;i++)
//    {
//        if(maxfreqsum<mp[i])
//        {
//            maxfreqsum=mp[i];
//            minsum=i;
//        }
//    }
//    cout<<minsum;
//}
//dailamsiu()
//{
//    if (fopen(task".inp", "r"))
//    {
//        freopen(task".inp", "r", stdin);
//        freopen(task".out", "w", stdout);
//    }
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    int ntest = 1; //cin >> ntest;
//    while (ntest--) solve();
//    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
//}
///cach 2: brute force
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
int s1,s2,s3;
void solve() {
    cin>>s1>>s2>>s3;
    int maxfreqsum=0,minsum=1e18;
    unordered_map<int,int>mp;
    for(int i=1;i<=s1;i++)
    {
        for(int j=1;j<=s2;j++)
        {
            for(int k=1;k<=s3;k++)
            {
                mp[i+j+k]++;
                if(maxfreqsum<mp[i+j+k])
                {
                    maxfreqsum=mp[i+j+k];
                    minsum=i+j+k;
                }
            }
        }
    }
    cout<<minsum;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
