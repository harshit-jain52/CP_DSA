#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const ll INF = 1e18;

int main()
{
	FASTIO
	int n,m,x; cin >> n >> m >> x;
	vector<vector<vector<int>>>g(n+1,vector<vector<int>>(2));
	vector<vector<ll>>dist(n+1,vector<ll>(2,INF));
	vector<vector<ll>>vis(n+1,vector<ll>(2,false));

	while(m--){
		int u,v; cin >> u >> v;
		g[u][0].push_back(v);
		g[v][1].push_back(u);
	}

	dist[1][0]=0;
	dist[1][1]=x;
	priority_queue<tuple<ll,int,int>>pq;
	pq.push({0,1,0});
	pq.push({-x,1,1});

	while(!pq.empty()){
		auto [d,u,rev] = pq.top();
		pq.pop();

		if(vis[u][rev]) continue;
		vis[u][rev]=true;

		for(int v: g[u][rev]){
			if(dist[v][rev] > dist[u][rev]+1){
				dist[v][rev] = dist[u][rev]+1;
				pq.push({-dist[v][rev],v,rev});
			}
		}

		for(int v: g[u][1^rev]){
			if(dist[v][1^rev] > dist[u][rev]+x+1){
				dist[v][1^rev] = dist[u][rev]+x+1;
				pq.push({-dist[v][1^rev],v,1^rev});
			}
		}
	}

	cout << min(dist[n][0],dist[n][1]);
}