#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
const int N = 2e5+1;

int pow2[N];

void solve(){
    int n; string s;
    cin >> n >> s;
    
    int cta=0, ctq=0;
    int ans = 0;
    
    for(int i=0;i<n;i++){
        if(s[i]=='A') cta++;
        else if(s[i]=='B'){
            ans += (cta*1LL*pow2[ctq])%M;
            ans %= M;
            if(ctq>0) ans += (ctq*1LL*pow2[ctq-1])%M;
            ans %= M;
        }
        else{
            ans = (ans*2LL)%M;
            
            ans += (cta*1LL*pow2[ctq])%M;
            ans %= M;
            if(ctq>0) ans += (ctq*1LL*pow2[ctq-1])%M;
            ans %= M;
            
            ctq++;
        }
        // cout << ans << " ";
    }
    
    cout << ans << endl;
}

int main(){
    pow2[0]=1;
    for(int i=1;i<N;i++) pow2[i]=(2LL*pow2[i-1])%M;
    int t; cin >> t;
    while(t--) solve();
}