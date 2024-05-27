#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 3e5+1;

vector<int>g[N];
int dist[N];

void dfs(int v, int pp, int dd){
    dist[v]=dd;
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

    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,0,0);
    int end=1;
    for(int i=1;i<=n;i++){
        if(dist[i]>dist[end]) end=i;
    }

    dfs(end,0,0);
    int diam = *max_element(dist+1,dist+n+1);
    cout << diam*3<<endl;
}