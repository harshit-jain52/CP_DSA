#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 2e5+5;

vector<pii> g[N];
int indp[N], outdp[N];

void indfs(int v, int pp){
    indp[v]=0;
    for(auto ch: g[v]){
        if(ch.F==pp) continue;
        indfs(ch.F,v);
        indp[v] += (ch.S + indp[ch.F]);
    }
}

void outdfs(int v, int pp){
    for(auto ch: g[v]){
        if(ch.F==pp) continue;
        outdp[ch.F] += (1^ch.S) + outdp[v] + indp[v]-(indp[ch.F] + ch.S);
        outdfs(ch.F,v);
    }
}

void solve(){
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        g[i].clear();
        indp[i]=outdp[i]=0;
    }
    
    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        g[u].push_back({v,0});
        g[v].push_back({u,1});
    }
    
    indfs(1,0);
    outdfs(1,0);
    
    vector<int>ans;
    int minbad = n;
    for(int i=1;i<=n;i++){
        int tmp = indp[i]+outdp[i];
        if(tmp<minbad){
            minbad = tmp;
            ans.clear();
            ans.push_back(i);
        }
        else if(tmp==minbad) ans.push_back(i);
    }
    
    sort(ans.begin(),ans.end());
    cout << minbad<<endl;
    for(auto it: ans) cout << it << " ";
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}