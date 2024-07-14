#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

vector<int>g[N];
vector<int>tin(N,0), lo(N,0);
vector<bool>onStack(N,false);

int timer = 1;
void dfs(int v, stack<int> &st){
    st.push(v);
    onStack[v]=true;
    tin[v]=lo[v]=timer++;

    for(int ch: g[v]){
        if(!tin[ch]) dfs(ch,st);
        if(onStack[ch]) lo[v]=min(lo[v],lo[ch]);
    }

    if(tin[v]==lo[v]){
        while(!st.empty()){
            int node = st.top();
            st.pop();
            onStack[node]=false;
            lo[node]=tin[v];
            if(node==v) break;
        }
    }
}

int main(){
    int n,m; cin >> n >> m;
    while(m--){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
    }

    for(int i=1;i<=n;i++){
        if(!tin[i]){
            stack<int>st;
            dfs(i,st);
        }
    }

    map<int,vector<int>>scc;
    for(int i=1;i<=n;i++){
        scc[lo[i]].push_back(i);
    }

    vector<bool>ans(n+1,false);
    for(auto c: scc){
        if(c.second.size()<=1) continue;
        for(int node: c.second) ans[node]=true;
    }

    for(int i=1;i<=n;i++) cout << ((ans[i])?1:0) << " ";
}