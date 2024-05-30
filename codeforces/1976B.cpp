#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
    int n;
    cin >> n;
    ll a[n],b[n+1];

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n+1;i++) cin >> b[i];

    ll tot = 0, extra=2e9+1;
    for(int i=0;i<n;i++){
        tot += abs(a[i]-b[i]);
        if((a[i]<=b[n]&&b[n]<=b[i]) || (a[i]>=b[n]&&b[n]>=b[i])) extra=0;
        extra = min(extra,min(abs(a[i]-b[n]),abs(b[i]-b[n])));
    }

    cout << tot+extra+1<<endl;
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