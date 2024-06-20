#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int a=-1,e=-1,i=-1,o=-1,u=-1;
    string s; cin >> s;
    int n = s.size(), offset=0;
    ll ans = 0;
    
    for(int j=0;j<n;j++){
        switch(s[j]){
            case 'a':
                a=j;
                ans += 1+min({e,i,o,u})-offset;
                break;
            case 'e':
                e=j;
                ans += 1+min({a,i,o,u})-offset;
                break;
            case 'i':
                i=j;
                ans += 1+min({a,e,o,u})-offset;
                break;
            case 'o':
                o=j;
                ans += 1+min({a,e,i,u})-offset;
                break;
            case 'u':
                u=j;
                ans += 1+min({a,e,i,o})-offset;
                break;
            default:
                a=e=i=o=u=j;
                offset=j+1;
        }
    }
    
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}
