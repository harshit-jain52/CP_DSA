#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;
vector<int>g[N];
int init[N], target[N];
int op = 0;

void dfs(int v, int p, int up1, int up2){
    if(init[v]^up2 != target[v]){
        op++;
        up2^=1;
    }

    for(int ch: g[v]) if(ch!=p) dfs(ch,v,up2,up1);
}

int main()
{
    FASTIO
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1;i<=n;i++) cin >> init[i];   
    for(int i=1;i<=n;i++) cin >> target[i];

    dfs(1,0,0,0);
    cout << op;
}