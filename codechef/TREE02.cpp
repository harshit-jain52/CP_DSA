#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e4+4;

vector<int>g[N];
ll w[N];
int req,k;

ll dfs(int v, int p, ll lim){
    ll tot = w[v];
    vector<ll>vec;
    for(int ch: g[v]){
        if(ch==p) continue;
        vec.push_back(dfs(ch,v,lim));
        tot += vec.back();
    }

    sort(vec.begin(),vec.end());
    int idx = vec.size()-1;
    while(tot>lim && idx>=0){
        tot -= vec[idx--];
        req++;
    }

    return tot;
}

bool check(ll lim){
    req = 0;
    dfs(1,0,lim);
    return (req<=(k-1));
}

int main()
{
    FASTIO
    int n;
    cin >> n >> k;

    ll max_wt=-1,sum_wt=0;
    for(int i=1;i<=n;i++){
        cin >> w[i];
        max_wt=max(max_wt,w[i]);
        sum_wt+=w[i];
    }

    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    ll lo = max_wt, hi=sum_wt, mid;
    ll ans=hi;
    while(lo<=hi){
        mid = (lo+hi)/2;
        if(check(mid)){
            ans = mid;
            hi = mid-1;
        }
        else lo=mid+1;
    }
    
    cout << ans;
}