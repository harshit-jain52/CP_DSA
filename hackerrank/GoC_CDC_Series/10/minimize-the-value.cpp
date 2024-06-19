#include <iostream>
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    int ans = 1e9+1;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i) ans = min(ans,a[i]-a[i-1]);
    }
    cout << ans << endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
}