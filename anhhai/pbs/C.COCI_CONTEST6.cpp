#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define ft(v,d,n,x) for(int v=d;v<=n;v+=x)
#define fn(v,d,n,x) for(int v=d;v>=n;v-=x)
#define pii pair<int,int>
#define NAME "ten"
using namespace std;
int n,q,a[N],bit[N];
struct node
{
    int l,r,ans;
}g[N];
struct query
{
    int l,r;
}Q[N];
vector<int>like[N],buck[N];
void upd(int pos,int val)
{
    for(;pos<=n;pos+=pos&-pos)
    {
        bit[pos]+=val;
    }
}
int get(int pos)
{
    int s=0;
    for(;pos>0;pos-=pos&-pos)
    {
        s+=bit[pos];
    }
    return s;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(NAME".inp","r"))
    {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        like[a[i]].push_back(i);
    }
    for(int i=1;i<=q;i++)
    {
        cin>>Q[i].l>>Q[i].r;
        g[i].l=0,g[i].r=Q[i].r-Q[i].l+1;
        g[i].ans=0;
    }
    for(int rep=1;rep<=20;rep++)
    {
        for(int i=1;i<=n;i++)   buck[i].clear(),bit[i]=0;
        for(int i=1;i<=q;i++)
        {
            if(g[i].l<=g[i].r)
            {
                buck[(g[i].l+g[i].r)/2].push_back(i);
            }
        }
        for(int h=n;h>=1;h--)
        {
            for(int id:like[h]) upd(id,1);
            for(int id:buck[h])
            {
                if(get(Q[id].r)-get(Q[id].l-1)>=h)
                {
                    g[id].ans=h;
                    g[id].l=h+1;
                }
                else
                    g[id].r=h-1;
            }
        }
    }for(int i=1;i<=q;i++)  cout<<g[i].ans<<'\n';

}
