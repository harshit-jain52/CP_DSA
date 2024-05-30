#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+10;

vector<int>g[N];
bool dfs(int v, int p){
    bool ans = false;
    for(int ch: g[v]) if(ch!=p) ans |= !dfs(ch,v);
    return ans;
}

int main()
{
    FASTIO
    int n,t;
    cin >> n >> t;

    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int u; cin >> u;
    if(dfs(u,0)) cout << "Ron";
    else cout << "Hermione";
}