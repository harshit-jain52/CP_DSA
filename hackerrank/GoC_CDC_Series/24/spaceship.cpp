#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k; cin >> n >> k;
    int a[n+1];
    for(int i=1;i<=n;i++) cin >> a[i];
    
    map<int,int>ct;
    ct[0]++;
    int suff=0;
    for(int i=k+1;i<=n;i++){
        if(a[i]>a[k]) suff++;
        else suff--;
        ct[suff]++;
    }
    
    ll ans = ct[0];
    int pref=0;
    for(int i=k-1;i>=1;i--){
        if(a[i]>a[k]) pref++;
        else pref--;
        ans += ct[-pref];
    }
    
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}