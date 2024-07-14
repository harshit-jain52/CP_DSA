#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
typedef long long ll;
vector<vector<int>> pref;

void solve(){
    int n,q; cin >> n >> q;
    string s; cin >> s;

    pref.assign(n+1,vector<int>(26,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++) pref[i][j]+=pref[i-1][j];
        pref[i][s[i-1]-'a']++;
    }

    while(q--){
        int l,r; char c;
        cin >> l >> r >> c;
        l--; r--;
        int d = c-'a', len = r-l+1;

        ll ct = 0;
        ct += (len/n)*1LL*pref[n][d];

        if(len%n!=0){
            l=l%n+1;
            r=r%n+1;
            if(l<=r) ct += pref[r][d]-pref[l-1][d];
            else ct += (pref[r][d] + pref[n][d]-pref[l-1][d]);
        }
        cout << ct << endl;
    }
}

int main(){
    FASTIO
    int t; cin >> t;
    while(t--) solve();
}