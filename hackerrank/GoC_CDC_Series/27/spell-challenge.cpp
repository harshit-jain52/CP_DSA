#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>trie;
vector<bool>stop;

void insert(string &s){
    int node = 0, sz = s.length();
    for(int i=0;i<sz;i++){
        int c = s[i]-'a';
        if(!trie[node][c]){
            trie.push_back(vector<int>(26));
            stop.push_back(0);
            trie[node][c] = trie.size()-1;
        }
        node = trie[node][c];
    }
    stop[node]=true;
}

void solve(){
    trie.assign(1,vector<int>(26));
    stop.assign(1,false);
    
    int n; cin >> n;
    for(int i=0;i<n;i++){
        string a; cin >> a;
        insert(a);
    }
    
    string s; cin >> s;
    int sz = s.size();
    
    vector<bool>dp(sz+1,false);
    dp[sz]=true;
    
    for(int i=sz-1;i>=0;i--){
        int node = 0;
        
        for(int j=i;j<sz;j++){
            int c = s[j]-'a';

            if(!trie[node][c]) break;
            
            node = trie[node][c];

            if(stop[node]) dp[i] = (dp[i] || dp[j+1]);
        }
    }
    
    // for(int i=0;i<n;i++) cout << dp[i] << " ";
    cout << ((dp[0])?"YES\n":"NO\n");
}
int main(){
    int t; cin >> t;
    while(t--) solve();
}