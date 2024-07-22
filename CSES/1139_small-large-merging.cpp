#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;

vector<int>g[N];
set<int>colors[N];
int ans[N];

void dfs(int v, int pp){
    for(int ch: g[v]){
        if(ch==pp) continue;
        dfs(ch,v);

        if(colors[v].size()<colors[ch].size()) swap(colors[v],colors[ch]);
        for(int c: colors[ch]) colors[v].insert(c);
    }

    ans[v] = colors[v].size();
}

int main()
{
    FASTIO
    int n; cin >> n;
    
    for(int i=1;i<=n;i++){
        int c; cin >> c;
        colors[i].insert(c);
    }

    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,0);

    for(int i=1;i<=n;i++) cout << ans[i] << " ";
}