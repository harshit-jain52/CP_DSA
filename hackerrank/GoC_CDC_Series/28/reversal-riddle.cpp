#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    map<int,int>ct;
    
    ll ans = 0;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        ans += (i-ct[a]);
        ct[a]++;
    }
    
    cout << (ans+1) << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}