#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ten "cau"
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
string a,b;
string gen(string s)
{
    if(s.size()&1)
    {
        return s;
    }
    int n=s.size();
    string s1=gen(s.substr(0,n/2)),s2=gen(s.substr(n/2,n/2));
    if(s1<s2)   return s1+s2;
    else    return s2+s1;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>a>>b;
    cout<<(gen(a)==gen(b)?"YES":"NO");
}
