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
    int n,p; cin >> n >> p;

    double ans = pow(p/100.0,(double)(n-1)/n);
    cout << fixed << setprecision(15) << (ans*100-p) << endl;
}

int main(){
    setIO("line_by_line");

    int T; cin >> T;
    for(int t=1;t<=T;t++){
        cout << "Case #" << t << ": ";
        solve();
    }
}