#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
    FASTIO
    int n,m; cin >> n >> m;
    ll l[n];
    for(int i=0;i<n;i++) cin >> l[i];

    ll lo = *max_element(l,l+n), hi = accumulate(l,l+n,1ll*n), mid;
    ll ans = hi;

    while(lo<=hi){
        mid = (lo+hi)/2;

        int ct = 1;
        ll pref=l[0];
        for(int i=1;i<n;i++){
            if(pref+1+l[i]<=mid) pref += 1+l[i];
            else{
                ct++;
                pref=l[i];
            }
        }

        if(ct<=m){
            ans = mid;
            hi=mid-1;
        }
        else lo = mid+1;
    }

    cout << ans;
}