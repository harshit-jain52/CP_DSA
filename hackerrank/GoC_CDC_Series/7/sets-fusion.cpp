#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,m;
    ll k1,k2,g=0;
    cin >> n >> m >> k1 >> k2;
    ll a[n], b[m];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    g = k1*a[0]+k2*b[0];
    for(int i=1;i<n;i++) g = __gcd(g,abs(k1*(a[i]-a[0])));
    for(int i=1;i<m;i++) g = __gcd(g,abs(k2*(b[i]-b[0])));
    cout << g << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}