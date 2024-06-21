#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

ll arr[N];

int check(ll lim, int n){
    ll curr=arr[0];
    int ct=1;
    for(int i=1;i<n;i++){
        if(curr+arr[i]>lim){
            ct++;
            curr=0;
        }
        curr+=arr[i];
    }
    
    return ct;
}

void solve(){
    int n,k; cin >> n >> k;
    ll lo=0, hi=0, mid;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
        lo=max(lo,arr[i]);
        hi+=arr[i];
    }
    
    ll ans = hi;
    while(lo<=hi){
        mid = (lo+hi)/2;
        if(check(mid,n)<=k){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    
    cout << ans << '\n';
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}