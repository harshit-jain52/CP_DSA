#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll a,b;
    cin >> a >> b;
    
    ll g = __gcd(a,b);
    int ct=1;
    for(ll i=2;i*i<=g;i++){
        if(g%i==0) ct++;
        while(g%i==0) g/=i;
    }
    
    if(g>1) ct++;
    cout << ct << '\n';
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}