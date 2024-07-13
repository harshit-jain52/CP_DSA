#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LOG = 20;
typedef long long ll;
typedef pair<int,ll> pii;
#define F first
#define S second

vector<vector<pii>>g;
vector<vector<int>>up;
vector<vector<ll>>dp;
vector<int>depth;
vector<ll>wc;

void dfs(int v, int pp, int dep, ll wt){
    up[v][0]=pp;
    dp[v][0]=wt;
    depth[v]=dep;
    
    for(int i=1;i<LOG;i++){
        up[v][i]=up[up[v][i-1]][i-1];
        dp[v][i]=dp[v][i-1]+dp[up[v][i-1]][i-1];
    }
    
    for(auto ch: g[v]) if(ch.F!=pp) dfs(ch.F,v,dep+1,ch.S);
}

ll pathSum(int v, int k){
    ll path=0;
    for(int i=LOG-1;i>=0;i--){
        if((k>>i)&1){
            path += dp[v][i];
            v = up[v][i];
        }
    }
    return path;
}

void solve(){
    int n; cin >> n;
    g.assign(n+1,vector<pii>());
    up.assign(n+1,vector<int>(LOG,0));
    dp.assign(n+1,vector<ll>(LOG,0));
    depth.resize(n+1);
    wc.resize(n+1);
    
    for(int i=0;i<n-1;i++){
        int a,b,w; cin >> a >> b >> w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    
    for(int i=1;i<=n;i++) cin >> wc[i];
    
    dfs(1,0,0,0);
    
    ll tot = 0;
    for(int i=1;i<=n;i++){
        int lo=1,hi=depth[i],mid;
        int ans = 0;
        while(lo<=hi){
            mid = (lo+hi)/2;
            ll path = pathSum(i,mid);
            if(path<=wc[i]){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        tot += (ans+1);
    }
    cout << tot << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}
