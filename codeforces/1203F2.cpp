#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second

vector<vector<int>>dp;
vector<pii>vec;
int n;

int func(int idx, int lim){
    if(idx==n) return 0;
    if(dp[idx][lim]!=-1) return dp[idx][lim];

    int ans = func(idx+1,lim);
    if(lim>=vec[idx].F) ans = max(ans,1+func(idx+1,lim+vec[idx].S));

    return dp[idx][lim]=ans;
}

void solve(){
    int r;
    cin >> n >> r;

    vec.resize(n);
    dp.assign(n,vector<int>(r+300*n+1,-1));

    vector<pii>pos,neg;
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        if(b>=0) pos.push_back({a,b});
        else{
            a = max(a,-b);
            neg.push_back({a,b});
        }
    }

    sort(pos.begin(),pos.end(),[&](auto x, auto y){
        return x.F < y.F;
    });

    sort(neg.begin(),neg.end(),[&](auto x, auto y){
        return x.F + x.S > y.F + y.S;
    });

    
    int idx=0;
    for(auto i: pos) vec[idx++]=i;
    for(auto i: neg) vec[idx++]=i;

    int ans = func(0,r);
    cout << ans << endl;
}

int main(){
    int t=1;
    // cin >> t;
    while(t--) solve();
}