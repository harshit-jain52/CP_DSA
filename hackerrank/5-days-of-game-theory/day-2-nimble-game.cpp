#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    ll x = 0;
    for(int i=0;i<n;i++){
        ll c;
        cin >> c;
        if(c&1) x ^= i;
    }
    
    if(x) cout << "First";
    else cout << "Second";
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}