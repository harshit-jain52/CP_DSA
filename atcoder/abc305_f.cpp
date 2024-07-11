#include <bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 105;
int n;
vector<bool>vis(N,false);

void dfs(int cur, int par){
	vis[cur]=true;
	string s; cin >> s;
	if(s=="OK" || s=="-1") exit(0);
	
	int k = stoi(s);
	bool flag = false;
	vector<int>adj(k);
	for(int i=0;i<k;i++){
		cin >> adj[i];
		if(adj[i]==n) flag = true;
	}

	if(flag){
		cout << n << endl;
		dfs(n,cur);
	}

	for(int i=0;i<k;i++){
		if(vis[adj[i]]) continue;
		cout << adj[i] << endl;
		dfs(adj[i],cur);
	}
	
	cout << par << endl;
	cin >> k;
	while(k--){
		int v; cin >> v;
	}
}

int main()
{
	int m; cin >> n >> m;
	dfs(1,0);		
}