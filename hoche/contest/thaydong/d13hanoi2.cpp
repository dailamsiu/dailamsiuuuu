#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ten "cau"
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int n;
void chuyen(int n,int c1,int c2)
{
    if(n==0)return;

    int c3=3-c1-c2;
    if(c2==(c1+1)%3)
    {
        chuyen(n-1,c1,c3);
        cout<<char(c1+'A');
        chuyen(n-1,c3,c2);
    }
    else
    {
        chuyen(n-1,c1,c2);
        cout<<char(c1+'A');
        chuyen(n-1,c2,c1);
        cout<<char(c3+'A');
        chuyen(n-1,c1,c2);
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
    chuyen(n,0,2);
}
