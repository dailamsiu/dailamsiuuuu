#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ten "cau"
using namespace std;
const int N=1e2+5;
const int mod=1e9+7;
int f[N+1][N+1][N+1];
int n,k;
int calc(int i,int c,int b)
{
    if(i>n)
    {
        return (c==0&&b==k);
    }
    if(f[i][c][b]>-1)return f[i][c][b];
    int cnt=calc(i+1,c+1,max(b,c+1));
    if(c>0) cnt+=calc(i+1,c-1,b);
    return f[i][c][b]=cnt;
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

    while(cin>>n>>k)
    {
        for(int i=0; i<=100; i++)
        {
            for(int j=0; j<=100; j++)
            {
                for(int k=0; k<=100; k++) f[i][j][k]=-1;
            }
        }

        string s=to_string(calc(1,0,0));
        if(s.size()>10)
        {
            for(int i=0; i<5; i++)    cout<<s[i];
            cout<<"...";
            for(int i=s.size()-5; i<s.size(); i++)    cout<<s[i];
        }
        else
        {
            cout<<s;
        }
        cout<<'\n';

    }
}
