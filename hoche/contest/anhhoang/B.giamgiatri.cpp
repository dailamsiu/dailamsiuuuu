///y tuong:gia su ai duoc chon lam muc tieu tru x di ci lan=> tong gia tri ai sau k thao tac: ci*x+(k-ci)*y
///de ai<0=> ai-(ci*x+(k-ci)*y)<0=>ai-ci*x-k*y+ci*y<0=>-(ci*(x-y))<k*y-ai->ci*(x-y)>ai-k*y
/// th1: x==y => 0>ai-k*y=> neu ai>k*y  return 0
///th2: x>y=>ci>(ai-k*y)/(x-y)
///neu ai-k*y<0-> ci=0
///neu ai-k*y>=0->kq+=(ai-k*y)/(x-y)+1
///th3: x<y=> ci<(k*y-ai)/(y-x)=>k*y-ai>0
///so lan toi da dc phep chon: maxc=(k*y-ai-1)/(y-x)
/// kq+=min(k,maxc)
/// return kq>=k
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ten "cau"
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int n,x,y,a[N];
bool check(int k)
{int res=0;
    if(x==y)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=k*y)    return 0;
        }
        return 1;
    }

    else if(x>y)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]-k*y>=0)
            {
                res+=(a[i]-k*y)/(x-y)+1;
            }
        }
        return res<=k;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(k*y-a[i]<=0) return 0;
            res+=min(k,(k*y-a[i]-1)/(y-x));
        }
        return res>=k;
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
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int l=0,r=1e10,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans;
}
