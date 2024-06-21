#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;

int par[N], sz[N];
ll wt[N], sk[N];
ll dp[N][10001];

void make(int v){
    par[v]=v;
    sz[v]=1;
}

int Find(int v){
    return ((par[v]==v)?v:par[v]=Find(par[v]));
}

void Union(int u,int v){
    u = Find(u); v = Find(v);
    if(u==v) return;
    
    if(sz[u]<sz[v]) swap(u,v);
    par[v]=u;
    sz[u]+=sz[v];
    wt[u]+=wt[v];
    sk[u]+=sk[v];
}

void solve(){
    int n,m,b; cin >> n >> m >> b;
    for(int i=1;i<=n;i++) make(i);
    for(int i=1;i<=n;i++) cin >> wt[i];
    for(int i=1;i<=n;i++) cin >> sk[i];
    
    while(m--){
        int p,q; cin >> p >> q;
        Union(p,q);
    }
    
    set<int>grps;
    for(int i=1;i<=n;i++) grps.insert(Find(i));
    
    int num = grps.size();
    ll s[num+1],w[num+1];
    int idx=1;
    for(auto it: grps){
        s[idx]=sk[it];
        w[idx]=wt[it];
        idx++;
    }
    // for(int i=1;i<=num;i++) cout << s[i]<<" "<<w[i]<<endl;
    for(int j=0;j<=b;j++) dp[0][j]=0;
    for(int i=1;i<=num;i++){
        for(int j=0;j<=b;j++){
            dp[i][j] = dp[i-1][j];
            if(w[i]<=j) dp[i][j] = max(dp[i][j],s[i]+dp[i-1][j-w[i]]);
        }
    }
    
    cout << dp[num][b]<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
}