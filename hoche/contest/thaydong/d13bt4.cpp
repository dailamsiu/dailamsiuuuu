#include<bits/stdc++.h>
#define int long long
#define ten "cau"
using namespace std;
typedef __int128 int128;
const int N=1e2+5;
int128 f[N][N][N];
int dd[N],n,k;
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
int128 calc(int i,int c,int b)
{
    if(i>n)return(c==0&&b==k);
    if(c>n-i+1)return 0;
    if(f[i][c][b]!=-1)return f[i][c][b];
    int128 cnt=calc(i+1,c+1,max(b,c+1));
    if(c>0&&!dd[i])cnt+=calc(i+1,c-1,b);
    return f[i][c][b]=cnt;
}
void xuli(string s)
{
    int d=0;
    for(int i=1; i<s.size()-1; i++)
    {
        if(isdigit(s[i]))d=d*10+s[i]-'0';
        else
        {
            dd[d]=1;
            d=0;
        }
    }
    if(d>0)dd[d]=1;
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
    string s;
    while(cin>>n>>k>>s)
    {
        memset(dd,0,sizeof(dd));
        xuli(s);
        if(n%2)
        {
            cout<<0<<'\n';
            continue;
        }
        memset(f,-1,sizeof(f));
        string res=to_string_128(calc(1,0,0));
        if(res.size()>10)cout<<res.substr(0,5)<<"..."<<res.substr(res.size()-5)<<'\n';
        else cout<<res<<'\n';
    }
}
