#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ten "cau"
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int nx[205][205],ny[205][205],m,n,k,dp[205][205][205];
string x,y;
int calc(int i,int px,int py)
{
    if(i>n)
    {
        return px<=x.size()&&py==y.size()+1;
    }
    if(px==x.size()+1)    return 0;
    if(dp[i][px][py]!=-1)    return dp[i][px][py];
    int cnt=0;
    for(int c=0; c<=25; c++)
    {
        cnt=(cnt+calc(i+1,nx[px][c],ny[py][c]))%k;
    }
    return dp[i][px][py]=cnt;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>m>>n>>k>>x>>y;
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<=25; i++)
    {
        nx[x.size()][i]=x.size()+1;
        nx[x.size()+1][i]=x.size()+1;
    }
    for(int i=0; i<=25; i++)
    {
        ny[y.size()][i]=y.size()+1;
        ny[y.size()+1][i]=y.size()+1;
    }
    for(int i=x.size()-1; i>=0; i--)
    {
        for(int c=0; c<=25; c++)
        {
            nx[i][c]=nx[i+1][c];
        }
        nx[i][x[i]-'a']=i+1;
    }
    for(int i=y.size()-1; i>=0; i--)
    {
        for(int c=0; c<=25; c++)
        {
            ny[i][c]=ny[i+1][c];
        }
        ny[i][y[i]-'a']=i+1;
    }
    while(m--)
    {
        string s;
        cin>>s;
        int order=1,px=0,py=0,ok=1;
        for(int i=0; i<s.size(); i++)
        {
            int dx=s[i]-'a';
            for(int c=0; c<=dx-1; c++)
            {
                int npx=nx[px][c],npy=ny[py][c];
                order=(order+calc(i+2,npx,npy))%k;
            }
            px=nx[px][dx];
            py=ny[py][dx];
            if(px==x.size()+1)
            {
                ok=0;
                break;
            }
        }
        if(!ok||px==x.size()+1||py!=y.size()+1)  cout<<-1<<'\n';
        else    cout<<order%k<<'\n';
    }
}
