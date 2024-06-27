#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 16;

ll x[16],y[16];
double dp[N][1<<N];
int n;

double dist(int i, int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
double func(int idx, int mask){
    if(__builtin_popcount(mask)==n) return dist(0,idx);
    if(dp[idx][mask]>0) return dp[idx][mask];
    
    double ans = 1e15;
    for(int i=0;i<n;i++){
        if(((mask>>i)&1)==0){
            ans = min(ans,dist(i,idx)+func(i,mask|(1<<i)));
        }
    }
    return dp[idx][mask]=ans;
}

void solve(){
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i=0;i<n;i++) cin >> x[i] >> y[i];
    
    double ans = 1e15;
    for(int i=1;i<n;i++){
        ans = min(ans,dist(0,i)+func(i,(1<<i)|1));
    }
    cout << (ll)ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}