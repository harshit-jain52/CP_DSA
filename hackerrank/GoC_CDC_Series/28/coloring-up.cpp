#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M= 1e9+7;

void solve(){
    int n,k; cin >> n >> k;
    vector<int>y(n+1,0);
    vector<int>b(n+1);
    
    while(k--){
        int u,v; cin >> u >> v;
        y[u]++; y[v]++;
    }
    
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ll b = n-1-y[i];
        ans += b*y[i];
    }
    
    cout << (ans/2)%M <<endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}