#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 101;

vector<int>g[N],rg[N];
bool vis[N], rvis[N];
vector<int>topo;
int comp=0;

void dfs(int v){
    vis[v]=true;
    for(int u: g[v]) if(!vis[u]) dfs(u);
    topo.push_back(v);
}

void rdfs(int v){
    rvis[v]=true;
    for(int u: rg[v]) if(!rvis[u]) rdfs(u);
}

void reset(int n){
    for(int i=0;i<=n;i++){
        g[i].clear();
        rg[i].clear();
        vis[i]=rvis[i]=false;
    }
    comp=0;
    topo.clear();
}

void solve(){
    int n;
    cin >> n;

    reset(n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin >> c;
            if(c=='Y'){
                g[i].push_back(j);
                rg[j].push_back(i);
            }
        }
    }

    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
    reverse(topo.begin(),topo.end());

    for(int i: topo) if(!rvis[i]){comp++; rdfs(i);}
    cout << comp<<endl;
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}