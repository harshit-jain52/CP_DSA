#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

vector<int>g[N];
vector<pair<int,int>>bridges;
int tin[N],lo[N],timer;

void dfs(int cur, int par){
    tin[cur]=lo[cur]= ++timer;

    for(int ch:g[cur]){
        if(ch==par) continue;

        if(tin[ch]) lo[cur]=min(lo[cur],tin[ch]);
        else{
            dfs(ch,cur);
            if(lo[ch]>tin[cur]) bridges.push_back({min(cur,ch),max(cur,ch)});
            lo[cur]=min(lo[cur],lo[ch]);
        }
    }
}

void reset(int n){
    for(int i=0;i<=n;i++){
        g[i].clear();
        tin[i]=0;
        lo[i]=0;
    }
    timer=0;
    bridges.clear();
}

void solve(){
    int n,m;
    cin >> n >> m;
    reset(n);
    while(m--){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(!tin[i]) dfs(i,0);
    }

    if(bridges.empty()) cout << "Sin bloqueos"<<endl;
    else{  
        sort(bridges.begin(),bridges.end());
        cout << bridges.size()<<endl;
        for(auto br: bridges) cout << br.first<<" "<<br.second<<endl;    
    }
    
}

int main()
{
    FASTIO
    int t;
    cin >>t;
    for(int i=1;i<=t;i++){
        cout << "Caso #"<<i<<endl;
        solve();
    }
}