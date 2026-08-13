#include<bits/stdc++.h>
#define int long long
#define N 1005
#define NAME "ten"
#define pii pair<int,int>
using namespace std;
int n,m,q,bit[4][N][N];
void upd(int t,int x,int y,int val)
{
    for(int i=x;i<=n;i+=i&-i)
    {
        for(int j=y;j<=m;j+=j&-j)
        {
            bit[t][i][j]+=val;
        }
    }
}
int que(int t,int x,int y)
{
    int res=0;
    for(int i=x;i>0;i-=i&-i)
    {
        for(int j=y;j>0;j-=j&-j)
        {
            res+=bit[t][i][j];
        }
    }
    return res;
}
void upd_point(int x,int y,int val) {
    upd(0,x,y,val);
    upd(1,x,y,val*(x-1));
    upd(2,x,y,val*(y-1));
    upd(3,x,y,val*(x-1)*(y-1));
}
void upd_hcn(int x1,int y1,int x2,int y2,int val)
{
    upd_point(x1,y1,val);
    upd_point(x1,y2+1,-val);
    upd_point(x2+1,y1,-val);
    upd_point(x2+1,y2+1,val);
}
int get_sum(int x,int y)
{
    return que(0,x,y)*x*y-que(1,x,y)*y-que(2,x,y)*x+que(3,x,y);
}
int get_hcn(int x1,int y1,int x2,int y2)
{
    return get_sum(x2,y2)-get_sum(x1-1,y2)-get_sum(x2,y1-1)+get_sum(x1-1,y1-1);
}
main()
{
    if(fopen(NAME ".inp","r"))
    {
        freopen(NAME ".inp","r",stdin);
        freopen(NAME ".out","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x;cin>>x;
            upd_point(i,j,x);
        }
    }
    while(q--)
    {
        int t;cin>>t;
        if(t==1)
        {
            int a,b,x,y,w;cin>>a>>b>>x>>y>>w;
            upd_hcn(a,b,x,y,w);
        }
        else
        {
            int a,b,x,y;cin>>a>>b>>x>>y;
            cout<<get_hcn(a,b,x,y)<<'\n';
        }
    }
}
