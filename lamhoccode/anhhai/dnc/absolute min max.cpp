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
int n,a[N],ans;
void calc(int l, int r)
{
    if(l>=r)
    {
        ans++;
        return;
    }
    int mid=(l+r)/2;
    calc(l,mid);
    calc(mid+1,r);
    vector<int> ML(mid-l+1), mL(mid-l+1), MR(r-mid), mR(r-mid);
    ML[0]=mL[0]=a[mid];
    for(int k=1; k<mid-l+1; k++)
    {
        ML[k]=max(ML[k-1],a[mid-k]);
        mL[k]=min(mL[k-1],a[mid-k]);
    }
    MR[0]=mR[0]=a[mid+1];
    for(int k=1; k<r-mid; k++)
    {
        MR[k]=max(MR[k-1],a[mid+1+k]);
        mR[k]=min(mR[k-1],a[mid+1+k]);
    }
    vector<int> prefA(r-mid+1,0), prefB(r-mid+1,0);
    for(int k=0; k<r-mid; k++)
    {
        prefA[k+1]=prefA[k]+(a[mid+1+k]==mR[k]?1:0);
        prefB[k+1]=prefB[k]+(a[mid+1+k]==MR[k]?1:0);
    }
    // ai max aj min

    int p1=-1, p2=0;
    for(int ki=0; ki<mid-l+1; ki++)
    {
        if(a[mid-ki]!=ML[ki]) continue;
        while(p1+1<r-mid && MR[p1+1]<=ML[ki]) p1++;
        while(p2<r-mid && mR[p2]>mL[ki]) p2++;
        if(p2<=p1) ans += prefA[p1+1]-prefA[p2];

    }

    //ai min aj max
    int p3=0, p4=-1;
    for(int ki=0; ki<mid-l+1; ki++)
    {
        if(a[mid-ki]!=mL[ki]) continue;
        while(p3<r-mid && MR[p3]<ML[ki]) p3++;
        while(p4+1<r-mid && mR[p4+1]>=mL[ki]) p4++;
        if(p3<=p4) ans += prefB[p4+1]-prefB[p3];

    }
    // lặp
    if(a[mid]==a[mid+1])
    {
        int cl=0;
        while(cl<mid-l+1 && a[mid-cl]==a[mid]) cl++;
        int cr=0;
        while(cr<r-mid && a[mid+1+cr]==a[mid+1]) cr++;
        ans -= (int)cl*cr;
    }
}
void solve() {
    cin>>n;
    FOR(i,0,n-1)  cin>>a[i];
    ans=0;
    calc(0,n-1);
    cout<<ans<<'\n';
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
