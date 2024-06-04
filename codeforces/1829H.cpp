#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    map<int,int>ct;
    for(int i=0;i<n;i++){
        auto prevct = ct;
        for(auto it: prevct){
            int AND = a[i]&it.first;
            ct[AND]+=it.second;
            ct[AND]%=M;
        }
        ct[a[i]]++;
        ct[a[i]]%=M;
    }

    int ans = 0;
    for(auto it: ct){
        if(__builtin_popcount(it.first)==k){
            ans += it.second;
            ans %= M;
        }
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