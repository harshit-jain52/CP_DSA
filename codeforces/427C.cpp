#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define F first
#define S second
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

vector<int>g[N];
int id[N],lo[N];
bool onStack[N];
int timer=0;

void dfs(int v, stack<int>&st){
    id[v] = lo[v] = ++timer;
    st.push(v);
    onStack[v]=true;

    for(int ch: g[v]){
        if(!id[ch]) {
            dfs(ch,st);
            lo[v]=min(lo[v],lo[ch]);
        }
        else if(onStack[ch]) lo[v]=min(lo[v],id[ch]);
    }

    if(id[v]==lo[v]){
        while(!st.empty()){
            int node = st.top();
            st.pop();
            onStack[node]=false;
            lo[node]=id[v];
            if(node==v) break;
        }
    }
}

int main()
{
    FASTIO
    int n,m;
    cin >> n;
    ll c[n+1];
    for(int i=1;i<=n;i++) cin >> c[i];

    cin >> m;
    while(m--){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    stack<int>st;
    for(int i=1;i<=n;i++) if(!id[i]) dfs(i,st);

    map<int,pair<ll,int>>mp;
    for(int i=1;i<=n;i++){
        int comp = lo[i];
        if(mp.find(comp) == mp.end() || mp[comp].F>c[i]) mp[comp]={c[i],1};
        else if(mp[comp].F == c[i]) mp[comp].S++;
    }

    ll cost=0,ways=1;
    for(auto it: mp){
        cost += it.S.F;
        ways = (ways*it.S.S)%M;
    }

    cout << cost << " "<<ways<<endl;
}