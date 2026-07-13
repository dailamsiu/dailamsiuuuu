#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ten "cau"
using namespace std;
typedef __int128 int128;
const int N=1e2+5;
const int mod=1e9+7;
int128 f[N][N];
int n;
string to_string_128(int128 num)
{
    if(num==0)return "0";
    string res="";
    while(num>0)
    {
        res+=(char)(num%10+'0');
        num/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}
int128 calc(int i,int c)
{
    if(i>n)return(c==0);
    if(c>n-i+1)return 0;
    if(f[i][c]!=-1)return f[i][c];
    int128 cnt=calc(i+1,c+1);
    if(c>0)cnt+=calc(i+1,c-1);
    return(f[i][c]=cnt);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    while(cin>>n)
    {
        if(n%2)
        {
            cout<<0<<'\n';
            continue;
        }
        memset(f,-1,sizeof(f));
        string s=to_string_128(calc(1,0));
        if(s.size()>10)cout<<s.substr(0,5)<<"..."<<s.substr(s.size()-5)<<'\n';
        else cout<<s<<'\n';
    }
}
