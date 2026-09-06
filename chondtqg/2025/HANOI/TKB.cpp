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
    string s;
    int k;
    bool check(char x)
    {
        return x=='a'||x== 'e'||x== 'o'||x=='u'||x== 'i';
    }
    void solve() {
        cin>>s>>k;
        int res=0;
        vector<pair<int,vector<int>>>q;
        for(int i=0;i<s.size();)
        {
            int t=check(s[i]);
            vector<int>cur;
            while(i<s.size()&&check(s[i])==t)  
            {
                cur.push_back(s[i++]);
            }
            q.push_back({t,cur});
        }
        int ans=0;
        for(int i=0;i<q.size()-1;i++)
        {
            vector<int>x,y;
            if(q[i].first)
            {
                int cur=0;
                for(int j=q[i].second.size()-1;j>=0;j--)
                {
                    cur+=q[i].second[j];
                    x.push_back(cur);
                }
                cur=0;
                for(auto d:q[i+1].second)
                {
                    cur+=d;
                    y.push_back(cur);
                }
            }
            else
            {
                int cur=0;
                for(int j=q[i].second.size()-1;j>=0;j--)
                {
                    cur+=q[i].second[j];
                    y.push_back(cur);
                }
                cur=0;
                for(auto d:q[i+1].second)
                {
                    cur+=d;
                    x.push_back(cur);
                }
            }
            int l=0,r=0,p=x.size();
            for(auto ny:y)
            {
                while(l<p&&x[l]<ny) l++;
                while(r<p&&x[r]<=ny+k)  r++;
                if(r>l) ans+=r-l;
            }
        }
        cout<<ans;
    }
    dailamsiu() {
        if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
        ios::sync_with_stdio(0); cin.tie(0);
        int ntest = 1; //cin >> ntest;
        while (ntest--) solve();
    }