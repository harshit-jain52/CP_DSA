#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    int n = s.size();
    vector<int>ans(n,0);
        
    for(int i=0;i<n;i++){
        int car = s[i]-'0';
        
        for(int j=0;j<n;j++){
            int num = 2*ans[j]+car;
            ans[j]=num%6;
            car = num/6;
        }
    }
    
    while(ans.back()==0 && ans.size()>1) ans.pop_back();
    int sz = ans.size();
    reverse(ans.begin(),ans.end());
    for(int i=0;i<sz;i++) cout << ans[i];
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}