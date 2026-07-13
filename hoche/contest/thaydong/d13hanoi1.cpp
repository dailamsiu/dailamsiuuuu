#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ten "cau"
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int n;
vector<string>t;
void gen(int n,char a,char b,char c)
{
    if(n==0)
    {
        return;
    }
    gen(n-1,a,c,b);
    cout<<a<<c<<'\n';
    gen(n-1,b,a,c);
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
    gen(n,'A','B','C');

}
