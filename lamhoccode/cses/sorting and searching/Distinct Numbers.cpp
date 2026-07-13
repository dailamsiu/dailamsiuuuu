#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int n,a[N];
main()
{
    cin>>n;unordered_set<int>s;
    s.reserve(1000005);
    s.max_load_factor(0.25);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];s.insert(a[i]);
    }
    cout<<s.size();



}
