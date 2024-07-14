#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    vector<int>ans(n,0);
    
    for(int i=0;i<n;i++) cin >> a[i];
    reverse(a,a+n);
    
    for(int i=0;i<n;i++){
        int car = a[i];
        
        for(int j=0;j<n;j++){
            int num = 2*ans[j]+car;
            ans[j]=num%6;
            car = num/6;
        }
    }
    
    while(ans.back()==0 && ans.size()>1) ans.pop_back();
    int sz = ans.size();
    for(int i=0;i<sz;i++) cout << ans[i] << " ";
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}