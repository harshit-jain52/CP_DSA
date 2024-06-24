#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

vector<int>g[N];
int dp[N][26], ch[N];

void dfs(int v, int pp){
    dp[v][ch[v]]++;
    
    for(int u: g[v]){
        if(u==pp) continue;
        dfs(u,v);
        for(int i=0;i<26;i++) dp[v][i] += dp[u][i];
    }
}

int main(){
    int n,q; cin >> n >> q;
    for(int i=1;i<=n;i++){
        char c; cin >> c;
        ch[i] = c-'a';
    }
    
    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1,0);
    
    while(q--){
        int m; string s;
        cin >> m >> s;
        
        vector<int>req(26,0);
        for(char c: s) req[c-'a']++;
        
        int ans = 0;
        for(int i=0;i<26;i++) ans += max(0,req[i]-dp[m][i]);
        
        cout << ans << endl;
    }
}