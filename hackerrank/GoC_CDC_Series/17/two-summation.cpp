#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int M = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<pii>vec(n);
    for(int i=0;i<n;i++) cin >> vec[i].F;
    for(int i=0;i<n;i++) cin >> vec[i].S;
    
    sort(vec.begin(),vec.end(),[&](auto a, auto b){return a.F+b.S < b.F+a.S;});
    int ans = 0;
    int pref = 0;
    for(int i=0;i<n;i++){
        ans += ((i*1LL*vec[i].F)%M + pref)%M;
        ans %= M;
        pref += vec[i].S;
        pref%=M;
    }
    
    // cout << ans << " ";
    ans*=2;
    ans%=M;
    
    for(int i=0;i<n;i++){
        ans += (vec[i].F + vec[i].S)%M;
        ans %= M;   
    }

    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}