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
    int n; cin >> n;
    double err = 1e-7;
    double maxsp=1e7, minsp=0;
    for(int i=1;i<=n;i++){
        int a,b; cin >> a >> b;
        if(a>0) maxsp = min(maxsp, (double)i/a);
        minsp = max(minsp, (double)i/b);
    }

    if(minsp - maxsp > err) cout << -1 << endl;
    else cout << fixed << setprecision(9) << minsp << endl;
}

int main(){
    setIO("subsonic_subway");

    int T; cin >> T;
    for(int t=1;t<=T;t++){
        cout << "Case #" << t << ": ";
        solve();
    }
}