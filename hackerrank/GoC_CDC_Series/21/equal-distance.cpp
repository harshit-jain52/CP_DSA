#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
#define F first
#define S second
const int N = 1e6+6;
vector<pii>g[N];
int ans = 0;

ll dfs(int v, int pp){
    ll len = 0;
    vector<ll>vec;
    
    for(auto ch: g[v]){
        if(ch.F==pp) continue;
        vec.push_back(ch.S + dfs(ch.F,v));
    }
    
    if((int)vec.size() == 2){
        ans += (vec[0]!=vec[1]);
        len = max(vec[0],vec[1]);
    }
    
    return len;
}

int main(){
    int n; cin >> n;
    for(int i=0;i<n-1;i++){
        int x,y,l; cin >> x >> y >> l;
        g[x].push_back({y,l});
        g[y].push_back({x,l});
    }
    
    dfs(1,0);
    cout << ans;
}