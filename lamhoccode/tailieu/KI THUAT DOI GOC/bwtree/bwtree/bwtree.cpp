#include <bits/stdc++.h>
using namespace std;
#define thn 0969156825
const int N = 200001;
int n, a[N], KQ[N], F[N];
vector<int> KE[N];
 
void DFS(int u,int p) {
    F[u]=a[u];
    for (auto v : KE[u]) {
        if (v!=p) {
            DFS(v,u);
            F[u]+=max(0,F[v]);
        }
    }
}
 
void doigoc(int u, int p) {
    KQ[u] = F[u];
    int Fu, Fv;
    for (auto v : KE[u]) {
        if (v!=p) {
            Fu=F[u]; 
            Fv=F[v]; 
            F[u]-=max(0, F[v]);
            F[v]+=max(0, F[u]);
            doigoc(v,u);
            F[u]=Fu; 
            F[v]=Fv; 
        }
    }
}
 
void xuli() {
    DFS(1,0);
    doigoc(1,0);
    for (int u=1; u<=n; u++) cout<<KQ[u]<<endl;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("BWTREE.INP","r", stdin);
	freopen("BWTREE.OUT","w", stdout);
	int x,y,i;
	cin>>n;
	for (i=1; i<=n; i++) {
		cin>>a[i];
		if (a[i]==0) a[i]=-1;
	}
	for (i=1; i<n; i++) {
		cin>>x>>y;
		KE[x].push_back(y);
		KE[y].push_back(x);
	}
	xuli();
	return 0;
}
