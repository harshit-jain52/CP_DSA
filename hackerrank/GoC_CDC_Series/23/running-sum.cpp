#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int n; int a[N];

bool check(ll x){
    ll pref = x;
    for(int i=0;i<n;i++){
        pref += a[i];
        if(pref<1) return false;
    }
    return true;
}

void solve(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    
    ll ans = 1e15;
    ll lo = -1e9, hi = 1e15, mid;
    
    while(lo<=hi){
        mid = (lo+hi)/2;
        
        if(check(mid)){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}