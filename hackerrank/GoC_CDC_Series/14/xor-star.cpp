#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int>ct(61,0);
    for(int i=0;i<n;i++){
        ll a; cin >> a;
        for(int bit=0;bit<=60;bit++){
            if((a>>bit)&1) ct[bit]++;
        }
    }
    
    int ans=0;
    for(int bit=0;bit<=60;bit++){
        ans += (((ct[bit]*1LL*(n-ct[bit]))%M)*((1LL<<bit)%M))%M;
        ans %= M;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
}