#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;
const int LOG = 20;

vector<int>g[N];
vector<int>per[N];
vector<int>dp[N][LOG];
int depth[N], up[N][LOG];

vector<int>merge(vector<int>&v1, vector<int>&v2){
    vector<int>res;
    int i=0,j=0,ct=0;

    while(i<v1.size() && j<v2.size() && ct<10){
        if(v1[i]<v2[j]){
            res.push_back(v1[i]);
            i++; ct++;
        }
        else{
            res.push_back(v2[j]);
            j++; ct++;
        }
    }

    while(i<v1.size() && ct <10){
        res.push_back(v1[i]);
        i++; ct++;
    }

    while(j<v2.size() && ct <10){
        res.push_back(v2[j]);
        j++; ct++;
    }

    return res;
}

void dfs(int v, int pp, int dep){
    depth[v]=dep;
    up[v][0]=pp;
    dp[v][0]=per[v];

    for(int i=1;i<LOG;i++){
         up[v][i] = up[up[v][i-1]][i-1];
         dp[v][i] = merge(dp[v][i-1],dp[up[v][i-1]][i-1]);  
    }

    for(int ch: g[v]){
        if(ch==pp) continue;
        dfs(ch,v,dep+1);
    }
}

vector<int> pathVec(int u, int v){
    if(depth[u]<depth[v]) swap(u,v);
    
    vector<int> res;

    for(int i=LOG-1;i>=0;i--){
        if((depth[u]-depth[v])&(1<<i)){
            res = merge(res,dp[u][i]);
            u = up[u][i];
        }
    }
 
    if(u==v) return merge(res,per[u]);
 
    for(int i=LOG-1;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            res = merge(res,dp[u][i]);
            res = merge(res,dp[v][i]);
            u = up[u][i];
            v = up[v][i];
        }
    }
    
    res = merge(res,per[u]);
    res = merge(res,per[v]);
    res = merge(res,per[up[u][0]]);
    
    return res;
}

int main()
{
    FASTIO
    int n,m,q;
    cin >> n>>m>>q;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=m;i++){
        int c;
        cin >> c;
        per[c].push_back(i);
    }

    for(int i=1;i<=n;i++) sort(per[i].begin(),per[i].end());
    dfs(1,0,0);

    while(q--){
        int v,u,a;
        cin >> v >> u >> a;
        vector<int>tmp = (u==v)?per[u]:pathVec(u,v);
        int sz = min(a,(int)tmp.size());
        cout << sz << " ";
        for(int i=0;i<sz;i++) cout << tmp[i]<<" ";

        cout << endl;
    }
}