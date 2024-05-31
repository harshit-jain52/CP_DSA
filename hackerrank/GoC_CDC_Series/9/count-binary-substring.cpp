#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    
    int curr=1, last=0;
    ll ans = 0;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]) curr++;
        else{
            ans += min(curr,last);
            last=curr;
            curr=1;
        }
    }
    ans += min(curr,last);
    
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}