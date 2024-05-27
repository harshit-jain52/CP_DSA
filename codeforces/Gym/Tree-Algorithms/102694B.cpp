#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 3e5+5;

vector<int>g[N];
vector<int> dist(N), par(N);

void dfs(int v, int pp, int dd){
    dist[v]=dd;
    par[v]=pp;
    for(int ch: g[v]){
        if(ch==pp) continue;
        dfs(ch,v,dd+1);
    }
}

int main()
{
    FASTIO
    int n;
    cin >> n;

    dist.assign(n+1,0);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,0,0);
    int end1=1;
    for(int i=1;i<=n;i++){
        if(dist[i]>dist[end1]) end1=i;
    }

    dfs(end1,0,0);
    int end2=1;
    for(int i=1;i<=n;i++){
        if(dist[i]>dist[end2]) end2=i;
    }

    vector<int>path;
    int curr = end2;
    while(curr>0){
        path.push_back(curr);
        curr = par[curr];
    }

    int diam = path.size()-1;

    if(diam%2==0){
        int c = path[path.size()/2];
        dfs(c,0,0);
        for(int i=1;i<=n;i++) cout << diam + (dist[i]==diam/2)<<endl;
    }
    else{
        int c1=path[path.size()/2], c2 = path[(path.size()-1)/2];
        dist.assign(n+1,0);
        dfs(c1,c2,0);
        vector<int>dist1 = dist;
        dist.assign(n+1,0);
        dfs(c2,c1,0);
        vector<int>dist2=dist;

        for(int i=1;i<=n;i++) cout << diam + (dist1[i]==diam/2 || dist2[i]==diam/2)<<endl;
    }
}