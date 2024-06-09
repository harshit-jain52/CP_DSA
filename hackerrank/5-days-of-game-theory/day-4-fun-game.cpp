#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    
    vector<int>vec(n);
    for(int i=0;i<n;i++) vec[i]=i;
    
    sort(vec.begin(),vec.end(),[&](int i, int j){return a[i]+b[i]>a[j]+b[j];});
    
    ll asum=0,bsum=0;
    for(int i=0;i<n;i++){
        if(i&1) bsum+=b[vec[i]];
        else asum += a[vec[i]];
    }
    
    if(asum>bsum) cout << "First\n";
    else if(asum<bsum) cout << "Second\n";
    else cout << "Tie\n";
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}