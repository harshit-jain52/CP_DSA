#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+1;
const int M = 1e9+7;

int binpow(int a, int b){
    int ans = 1;
    while(b){
        if(b&1) ans = (ans*1LL*a)%M;
        a = (a*1LL*a)%M;
        b>>=1;
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    for(int i=0;i<n;i++){
        ll a; cin >> a;
    }
    
    int ans=0;
    for(int i=1;i<=n;i++){
        int contri = binpow(n-i+1,M-2);
        ans = (ans+contri)%M;
    }
    
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}