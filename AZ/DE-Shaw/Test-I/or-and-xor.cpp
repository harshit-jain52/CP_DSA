#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int M = 1e9+7;
int pow2[N];

void solve(){
    int n; cin >> n;
    map<int,int>ct;
    
    for(int i=0;i<n;i++){
        int a; cin >> a;
        ct[a]++;
    }

    int ans = 0;
    for(auto it: ct){
        if(it.first==0) ans = (ans+(pow2[it.second]-1+M)%M)%M;
        else ans = (ans + pow2[it.second-1])%M;
    }

    cout << ans << endl;
}

int main(){
    pow2[0]=1;
    for(int i=1;i<N;i++) pow2[i]=(2LL*pow2[i-1])%M;

    int t; cin >> t;
    while(t--) solve();
}