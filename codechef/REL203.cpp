#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
#define F first
#define S second
const int M = 1e9+7;
const int N = 2e4+4;

vector<pair<int,ll>>g[N];

void reset(int n){
    for(int i=0;i<=n;i++) g[i].clear();
}

ll dfs(int v, int p){
    ll maxd=0;
    for(auto e : g[v]) if(e.F != p) maxd=max(maxd,e.S+dfs(e.F,v));
    return maxd;
}

void solve(){
    int n; cin >> n;
    reset(n);

    ll tot_wt=0;
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        tot_wt+=2*w;
    }

    cout << tot_wt-dfs(1,0)<<endl;
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}