#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;

vector<int>g[N];
vector<int>deg(N,0), ans(N,0);
vector<bool>vis(N,false);

int dfs(int v, int par){
	vis[v]=true;
	vector<int>vec;
	for(int ch: g[v]){
		if(ch==par) continue;
		if(deg[ch]>=4) vec.push_back(dfs(ch,v));
	}

	while(vec.size()<4) vec.push_back(0);
	sort(vec.rbegin(),vec.rend());

	ans[v]=1+vec[0]+vec[1]+vec[2]+vec[3];
	return (ans[v]-vec[3]);
}

int main()
{
	FASTIO
	int n; cin >> n;

	for(int i=0;i<n-1;i++){
		int a,b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
		deg[a]++; deg[b]++;
	}

	int fin = 0;
	for(int i=1;i<=n;i++){
		if(!vis[i] && deg[i]>=4) dfs(i,0);
	}

	for(int i=1;i<=n;i++) fin = max(fin,ans[i]);

	cout << ((fin==0)?-1:3*fin+2);
}