#include <bits/stdc++.h>
using namespace std;

vector<int>g[505];

int hackenbush(int v, int par){
    int x = 0;
    
    // Colon Principle
    for(int ch: g[v]) if(ch!=par) x^=(1+hackenbush(ch,v));
    
    return x;
}

void solve(){
    int n; cin >> n;
    for(int i=0;i<=n;i++) g[i].clear();
    
    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    if(hackenbush(1,0)) cout << "Alice\n";
    else cout << "Bob\n";
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}