#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,k; cin >> n >> k;
    ll p[n];
    for(int i=0;i<n;i++) cin >> p[i];

    if(k==1 || k==n){
        cout << 0 << endl;
        return;
    }

    vector<ll>vec;
    for(int i=1;i<n;i++) vec.push_back(p[i]+p[i-1]);
    
    sort(vec.begin(),vec.end());
    ll b=0;
    for(int i=0;i<k-1;i++) b+=vec[i];

    reverse(vec.begin(),vec.end());
    ll a = 0;
    for(int i=0;i<k-1;i++) a+=vec[i];

    cout << (a-b) << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}

// https://www.hackerearth.com/problem/algorithm/candies-price-e28e51a2-cfa8f906/