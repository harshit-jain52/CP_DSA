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

double binpow(double a, int b){
    double res = 1;
    while(b){
        if(b&1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n, g; cin >> n >> g;
    int e[n];
    for(int i=0;i<n;i++) cin >> e[i];
    sort(e,e+n);

    int ans = 0;
    int mn = INT_MAX;

    for(int i=0;i<n;i++){
        int dist = abs(e[i]-g);
        if(dist <= mn){
            mn = dist;
            ans = n-i;
        }
    }
    cout << ans << " " << mn << endl;
}

int main(){
    setIO("line_of_delivery_part_1");

    int T; cin >> T;
    for(int t=1;t<=T;t++){
        cout << "Case #" << t << ": ";
        solve();
    }
}