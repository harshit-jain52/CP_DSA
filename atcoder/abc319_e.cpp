#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
    FASTIO
    // lcm of 1--8 = 840

    int n; cin >> n;
    ll x,y; cin >> x >> y;

    int p[n]; ll t[n];
    for(int i=1;i<n;i++) cin >> p[i] >> t[i];

    ll ans[840];
    for(int i=0;i<840;i++){
        ll last=i;
        for(int j=1;j<n;j++){
            ll extra = (p[j]-(last%p[j]))%p[j];
            last += extra+t[j];
        }
        ans[i] = last;
    }

    int q; cin >> q;
    while(q--){
        ll qi; cin >> qi;
        cout << qi+x - (qi+x)%840 +ans[(qi+x)%840]+y<<endl;
    }
}