///y tuong:gop lai thanh cac block pair voi first la id gia tri lon nhat trong doan, second la do dai doan
/// moi khoi phai dua vao a(0) hoac dua vao b(1)
/// tong suc chua phai bang n
///=> dung qhd knapsack(0/1)
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ten "cau"
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int n,c[N];
vector<pii>s;
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
    cin>>n;
    for(int i=1; i<=2*n; i++)
    {
        cin>>c[i];
    }
    for(int i=1; i<=2*n;)
    {
        int j=i+1;
        while(j<=2*n&&c[j]<c[i])
        {
            j++;
        }
        s.push_back({i,j-i});
        i=j;
    }
    vector<int>dp(n+1,-1);
    dp[0]=-36;
    for(int i=0; i<s.size(); i++)
    {
        for(int j=n; j>=s[i].second; j--)
        {
            if(dp[j]==-1&&dp[j-s[i].second]!=-1)
            {
                dp[j]=i;
            }
        }
    }
    if(dp[n]==-1)
    {
        cout<<-1;
        return 0;
    }
    vector<int>dd(s.size(),0);
    int i=n;
    while(i>0)
    {
        dd[dp[i]]=1;
        i-=s[dp[i]].second;
    }///trace
    vector<int>a,b;
    for(int i=0; i<s.size(); i++)
    {
        for(int k=1; k<=s[i].second; k++)
        {
            int val=c[k+s[i].first-1];
            if(dd[i])
            {
                a.push_back(val);
            }
            else
            {
                b.push_back(val);
            }
        }
    }
    for(auto x:a)   cout<<x<<' ';
    cout<<'\n';
    for(auto x:b)cout<<x<<' ';

}
