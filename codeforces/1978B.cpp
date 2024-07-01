#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
    ll n,a,b; cin >> n >> a >> b;
    if(a>=b){
        cout << a*n << endl;
        return;
    }
    ll diff = b-a;
    ll ans = a*n + diff*(diff+1)/2;
    if(diff>n){
        ll num = diff-n;
        ans -= num*(num+1)/2;
    }
    cout << ans << endl;
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}