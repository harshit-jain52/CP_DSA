#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9+7;
const int N = 1e7+1;

void setIO(string name = ""){
    cin.tie(0)->sync_with_stdio(0);
    if(name.size()){
        freopen((name + "_input.txt").c_str(), "r", stdin);
        freopen((name + "_output.txt").c_str(), "w", stdout);
    }
}

vector<bool>isPrime(N,true);
vector<int>cnt(N,0);

void sieve(){
    isPrime[0] = isPrime[1] = false;
    for(ll i=2;i<N;i++){
        if(isPrime[i]){
            cnt[i]=isPrime[i-2];
            for(ll j=i*i;j<N;j+=i) isPrime[j] = false;
        }
        cnt[i] += cnt[i-1];
    }
}

void solve(){
    int n; cin >> n;
    cout << cnt[n] + (n>=5) << endl;
}

int main(){
    setIO("prime_subtractorization");
    sieve();
    int T; cin >> T;
    for(int t=1;t<=T;t++){
        cout << "Case #" << t << ": ";
        solve();
    }
}