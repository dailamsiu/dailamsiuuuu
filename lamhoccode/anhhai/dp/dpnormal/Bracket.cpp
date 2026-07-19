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
#define task "tbrackets"
#define dailamsiu main
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) { assert(l <= r); return uniform_int_distribution<int>(l, r)(rd); }
const int N = 1e6 + 5;
const int mod = 998244353;
const int BASE = 3137;
const int BLSZ=448;
string s;
int dp[N];
stack<int>st;
bool check(char a,char b)
{
     return(a=='('&&b==')')||(a=='['&&b==']')||(a=='{'&&b=='}')||(a=='<'&&b=='>');
}
void solve() {
    cin>>s;
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='('||s[i]=='['||s[i]=='{'||s[i]=='<')
        {
            st.push(i);
        }
        else
        {
            if(st.size()&&check(s[st.top()],s[i]))
            {
                int j=st.top();st.pop();
                dp[i]+=dp[j-1]+1;
                ans+=dp[i];
            }
            else
            {
                while(st.size())    st.pop();
            }
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
