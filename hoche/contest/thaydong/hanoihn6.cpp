#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ten "cau"
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
vector<string>x;
int n;

void gen(int n,char a,char b,char c,char d)
{
    if(n==0)    return;
    if(n==1)
    {
        cout<<a<<d<<'\n';
        return;
    }
    if(n==2)
    {
    cout<<a<<b<<'\n';
    cout<<a<<d<<'\n';
   cout<<b<<d<<'\n';
        return;
    }
    gen(n-2,a,d,c,b);
    cout<<a<<c<<'\n';
    cout<<a<<d<<'\n';
    cout<<c<<d<<'\n';
    gen(n-2,b,a,c,d);
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
    if(n%2)
    {
        cout<<(1<<(n/2+2))-3;
    }
    else
    {
        cout<<3*(1<<(n/2))-3;
    }
    cout<<'\n';
    gen(n,'A','B','C','D');

}
