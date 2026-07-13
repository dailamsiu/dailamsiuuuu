#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ten "cau"
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int g[4][4],n;
vector<pair<char,char>>m;
void gen(int n,char a,char b,char c)
{
    if(n==0)    return;
    if(g[a-'A'][c-'A']==1)
    {
        gen(n-1,a,b,c);
        m.push_back({a,c});
        gen(n-1,b,c,a);
    }
    else
    {
        gen(n-1,a,c,b);
        m.push_back({a,b});
        gen(n-1,c,a,b);
        m.push_back({b,c});
        gen(n-1,a,c,b);
    }
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>g[i][j];
        }
    }
    gen(n,'A','B','C');
    cout<<m.size()<<'\n';
    for(auto x:m)
    {
        cout<<x.first<<x.second<<'\n';
    }
}
