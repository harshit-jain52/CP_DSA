#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 998244353;

int binpow(int a, int b){
    int ans=1;
    while(b){
        if(b&1) ans = (ans*1LL*a)%M;
        a = (a*1LL*a)%M;
        b>>=1;
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    int a[n];
    map<int,int>mp;
    
    for(int i=0;i<n;i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    
    int nume=0;
    for(auto it: mp){
        if(it.first==0) nume += (binpow(2,it.second)-1+M)%M;
        else nume += binpow(2,it.second-1);
        nume %= M;
    }
    // cout << nume<<" ";
    int deno = binpow((binpow(2,n)-1+M)%M,M-2);
    
    cout << (nume*1LL*deno)%M << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}