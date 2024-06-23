#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,k; cin >> n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    
    int i=0,j=0;
    ll curr = a[0];
    ll diff = INT_MAX;
    
    while(j<n){
        while(i<=j && curr>k){
            diff = min(diff,curr-k);
            curr -= a[i];
            i++;
        }
        
        if(i<=j) diff = min(diff,k-curr);
        
        j++;
        if(j<n) curr += a[j];
    }
    
    cout << diff << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}