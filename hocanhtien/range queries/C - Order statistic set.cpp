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
    int q,st[4*N],d,m;
    unordered_map<int,int>mp;
    struct node
    {
        char x;int y;
    }a[4*N];
    void upd(int id,int l,int r,int pos,int val)
    {
        if(pos<l||pos>r)    return;
        if(l==r)
        {
            st[id]=val;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid)    upd(id*2,l,mid,pos,val);
        else    upd(id*2+1,mid+1,r,pos,val);
        st[id]=st[id*2]+st[id*2+1];
    }
    int get(int id,int l,int r,int u,int v)
    {
        if(v<l||r<u)    return 0;
        else if(u<=l&&r<=v)
        {
            return st[id];
        }
        int mid=(l+r)/2;
        return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
    }
    int find(int id,int l,int r,int val,int temp=0)
    {
        if(l==r)    return r;
        int mid=(l+r)/2;
        if(temp+st[id*2]>=val)
        {
            return find(id*2,l,mid,val,temp);
        }
        else
        {
            return find(id*2+1,mid+1,r,val,temp+st[id*2]);
        }
    }
    void solve() {
        cin>>q;
        vector<int>v;
        for(int i=1;i<=q;i++)
        {
            cin>>a[i].x>>a[i].y;
            if(a[i].x!='K') v.push_back(a[i].y);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        m=v.size();
        for(int i=1;i<=q;i++)
        {
            if(a[i].x=='I'&&!mp[a[i].y])
            {
                int id = lower_bound(v.begin(), v.end(), a[i].y) - v.begin() + 1;
                mp[a[i].y]=1;
                d++;
                upd(1,1,m,id,1);
            }
            else if(a[i].x=='D'&&mp[a[i].y])
            {
                int id = lower_bound(v.begin(), v.end(), a[i].y) - v.begin() + 1;
                mp[a[i].y]=0;d--;upd(1,1,m,id,0);
            }
            else if(a[i].x=='C')
            {
                int id = lower_bound(v.begin(), v.end(), a[i].y) - v.begin();
                cout<<get(1,1,m,1,id)<<'\n';
            }
            else if(a[i].x=='K')
            {
                if(a[i].y>d)
                {
                    cout<<"invalid\n";
                }
                else
                {
                    cout<<v[find(1,1,m,a[i].y)-1]<<'\n';
                }
            }
        }
    }
    dailamsiu() {
        if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
        ios::sync_with_stdio(0); cin.tie(0);
        int ntest = 1; //cin >> ntest;
        while (ntest--) solve();
    }