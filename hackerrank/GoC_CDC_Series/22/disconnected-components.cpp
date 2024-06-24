#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
vector<int>g[N];
vector<bool> vis(N,false);

void dfs(int v, int &numN, int &numE){
    numN++;
    vis[v]=true;
    
    for(int ch: g[v]){
        numE++;
        if(vis[ch]) continue;
        dfs(ch,numN,numE);
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    int k; cin >> k;
    int d[k];
    for(int i=0;i<k;i++) cin >> d[i];
    
    ll ans = 0;
    int numN,numE;
    int maxN=0,sumN=0,sumE=0;
    
    for(int i=0;i<k;i++){
        numN = numE = 0;
        dfs(d[i],numN,numE);
        
        numE/=2;

        // cout << numN <<" "<<numE<<endl;
        sumN += numN;
        sumE += numE;
        maxN = max(maxN, numN);
        
        ll totE = (numN*1LL*(numN-1))/2;
        ans += totE - numE;
    }
    
    int exN = n-sumN, exE = m-sumE;
    ans += (exN*1LL*(exN-1))/2 - exE;
    ans += maxN*1LL*exN;
    cout << ans;
}