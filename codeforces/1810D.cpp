#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

ll days(ll a, ll b, ll h){
    return max(1LL,((h-b-1)/(a-b))+1);
}

void solve(){
    int q; cin >> q;
    ll lo = 1, hi = 1e18+5;
    while(q--){
        int type; cin >> type;
        ll a,b;
        if(type==1){
            ll n;
            cin >>a>>b>>n;
            ll tmp = (n-1)*(a-b);
            ll tmpl = tmp+b+1, tmpr = tmp+a;
            if(n==1) tmpl = 1, tmpr=a;
            
            if(tmpl > hi || tmpr < lo) cout << 0 << " ";
            else{
                cout << 1 << " ";
                lo = max(lo,tmpl);
                hi = min(hi,tmpr);
            }
            // cout << lo <<" "<<hi<<endl;
        }
        else{
            cin >> a>>b;
            ll d1 = days(a,b,lo), d2=days(a,b,hi);
            if(d1==d2) cout << d1<<" ";
            else cout << -1 << " ";
            // cout << endl<< d1<<" "<<d2<<endl;
        }
    }
    cout << endl;
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