#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    
    if(n<4){
        cout << 0 << endl;
        return;
    }
    
    ll vsuff[n],msuff[n];
    vsuff[n-1] = s[n-1]=='V';
    msuff[n-1] = s[n-1]=='M';
    
    for(int i=n-2;i>=0;i--){
        vsuff[i] = vsuff[i+1] + (s[i]=='V');
        msuff[i] = msuff[i+1] + (s[i]=='M');
    }
    
    ll vpref=0,mpref=0;
    ll ans = 0;
    
    for(int i=0;i<n;i++){
        if(s[i]=='V'){
            ans += vpref*msuff[i]*(msuff[i]-1)/2;
            vpref++;
        }
        else{
            ans += mpref*vsuff[i]*(vsuff[i]-1)/2;
            mpref++;
        }
    }
    
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}