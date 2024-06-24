#include <bits/stdc++.h>
using namespace std;

void solve(){
   string s,t; cin >> s >> t;
    vector<int>ct(26,0);
    vector<int>req(26,0);
    
    for(char c: t) req[c-'a']++;
    for(char c: s) ct[c-'a']++;
    
    int ans = INT_MAX;
    
    for(int i=0; i<26; i++){
        if(req[i]) ans = min(ans,ct[i]/req[i]);
    }
    
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}