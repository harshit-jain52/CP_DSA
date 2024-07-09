#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+10;

vector<int>g[N];
int indp[N], outdp[N];

void indfs(int v, int pp){
    indp[v]=0;
    for(int ch: g[v]){
    	if(ch==pp) continue;
    	indfs(ch,v);
    	indp[v] += (indp[ch]==0);
    }
}

void outdfs(int v, int pp){
	for(int ch: g[v]){
		if(ch==pp) continue;
		outdp[ch] += (outdp[v]+(indp[v]-(indp[ch]==0)) == 0);
		outdfs(ch,v);
	}
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

    indfs(1,0);
    outdfs(1,0);

    while(t--){
    	int u; cin >> u;
    	if(indp[u] || outdp[u]) cout << "Ron\n";
    	else cout << "Hermione\n";
    }
}