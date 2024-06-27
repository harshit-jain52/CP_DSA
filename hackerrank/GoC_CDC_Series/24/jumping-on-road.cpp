#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
#define F first
#define S second

int main(){
    int n,k; cin >> n >> k;
    ll w[n+1], dp[n+1];
    for(int i=1;i<=n;i++) cin >> w[i];
    
    multiset<pii>ms;
    ms.insert({0,0});
    
    for(int i=1;i<=n;i++){
        while((*ms.begin()).S < i-k) ms.erase(ms.begin());
        dp[i] = w[i] + (*ms.begin()).F;
        ms.insert({dp[i],i});
    }
    
    cout << dp[n] << endl;
}
