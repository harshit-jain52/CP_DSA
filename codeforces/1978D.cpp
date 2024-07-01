#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
    int n; ll c;
    cin >> n >> c;
    ll a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    a[0]+=c;
    ll maxr[n],maxl[n];
    maxr[n-1]=a[n-1];
    maxl[0]=a[0];

    for(int i=1;i<n;i++){
        maxl[i] = max(maxl[i-1],a[i]);
        maxr[n-i-1] = max(maxr[n-i],a[n-i-1]);
    }

    ll pref=0;
    for(int i=0;i<n;i++){
        if(maxr[i]<=a[i] && (i==0 || maxl[i-1]<a[i])) cout << 0 << " ";
        else{
            if(a[i]+pref>=maxr[i]) cout << i << " ";
            else cout << i+1<<" ";
        }
        pref += a[i];
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