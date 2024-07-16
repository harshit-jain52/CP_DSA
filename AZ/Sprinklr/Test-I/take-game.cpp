#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e17;

vector<vector<ll>>dp;
vector<ll>a;
int n;

ll func(int l, int r){
    if(l==r) return a[l];
    if(dp[l][r]!=-INF) return dp[l][r];

    int len = r-l+1;
    bool bob = (n-len)%2;

    if(bob) dp[l][r] = a[l]-func(l+1,r);
    else dp[l][r] = max(a[l]-func(l+1,r),a[r]-func(l,r-1));

    return dp[l][r];
}

void solve(){
    cin >> n;
    dp.assign(n+1,vector<ll>(n+1,-INF));
    a.resize(n);

    ll sum=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }


    ll maxdiff = func(0,n-1);

    cout << (maxdiff+sum)/2 << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}