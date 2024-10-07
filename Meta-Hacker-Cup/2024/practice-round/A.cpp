#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9+7;

void setIO(string name = ""){
    cin.tie(0)->sync_with_stdio(0);
    if(name.size()){
        freopen((name + "_input.txt").c_str(), "r", stdin);
        freopen((name + "_output.txt").c_str(), "w", stdout);
    }
}

void solve(){
    int n,k; cin >> n >> k;
    ll s[n];
    for(int i=0;i<n;i++) cin >> s[i];
    ll mn = *min_element(s,s+n);

    ll sec = ((n==1)?mn:mn*(2*n-3));
    cout << ((sec<=k)?"YES\n":"NO\n");
}

int main(){
    setIO("walk_the_line");

    int T; cin >> T;
    for(int t=1;t<=T;t++){
        cout << "Case #" << t << ": ";
        solve();
    }
}