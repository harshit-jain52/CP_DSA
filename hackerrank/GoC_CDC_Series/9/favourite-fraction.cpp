#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll CEIL(ll num, ll den){
    return (num+den-1)/den;
}

void solve(){
    ll a,b,x,y;
    cin >> a >> b >> x >> y;
    
    if(x==0){
        if(a==0) cout << 0 << endl;
        else cout << -1 << endl;
    }
    else if(x==y){
        if(a==b) cout << 0 << endl;
        else cout << -1 << endl;
    }
    else{
        ll k = max({CEIL(a,x),CEIL(b,y),CEIL(b-a,y-x)});
        cout << k*y-b << endl;
    }
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}