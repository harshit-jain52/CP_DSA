#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m; cin >> n >> m;
    
    vector<vector<int>>pref(n+1,vector<int>(26,0));
    vector<int>ct(26);
    
    for(int i=1;i<=n;i++){
        string a; cin >> a;
        ct.assign(26,0);
        for(int j=0;j<(int)a.length();j++) ct[a[j]-'a']++;
        
        for(int j=0;j<26;j++) pref[i][j] = pref[i-1][j]+ct[j];
    }
    
    while(m--){
        int l,r,k; cin >> l >> r >> k;
        int tmp=0;
        for(int j=0;j<26;j++){
            ct[j] = pref[r][j]-pref[l-1][j];
            tmp+=ct[j];
            if(tmp>=k) {
                char c = 'a'+j;
                cout << c << '\n';
                break;
            }
        }
        
    }
}