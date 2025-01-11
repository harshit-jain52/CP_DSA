#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<ll,int> pli;
#define F first
#define S second
const int M = 1e9+7;
const ll INF = 1e16;

void solve(){
	int n,m,h;
	cin >> n >> m >> h;

	vector<bool>horse(n+1,false);
	vector<vector<pli>>g(n+1);

	for(int i=0;i<h;i++){
		int a; cin >> a;
		horse[a]=1;
	}

	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back({w,v});
		g[v].push_back({w,u});
	}

	auto djikstra = [&](int src)->vector<vector<ll>>{
		priority_queue<tuple<ll,int,int>>pq;
		vector<vector<ll>>dist(n+1,vector<ll>(2,INF));
		vector<vector<bool>>vis(n+1,vector<bool>(2,false));
		dist[src][0]=0;
		pq.push({0,src,0});

		while(!pq.empty()){
			auto [_,u,ho] = pq.top();
			pq.pop();

			if(vis[u][ho]) continue;
			vis[u][ho] = true;

			for(auto [w,v]: g[u]){
				if(dist[v][0]>dist[u][ho]+w){
					dist[v][0]=dist[u][ho]+w;
					pq.push({-dist[v][0],v,0});	
				}

				if(ho || horse[u]){
					if(dist[v][1]>dist[u][ho]+w/2){
						dist[v][1]=dist[u][ho]+w/2;
						pq.push({-dist[v][1],v,1});
					}
				}
			}
		}

		return dist;
	};

	vector<vector<ll>>d1=djikstra(1);
	vector<vector<ll>>dn=djikstra(n);

	ll ans = INF;
	for(int i=1;i<=n;i++) ans = min({ans,max(d1[i][0],dn[i][1]),max(d1[i][1],dn[i][0]),max(d1[i][0],dn[i][0]),max(d1[i][1],dn[i][1])});

	// for(int i=1;i<=n;i++) if(d1[i]+dn[i]==ans) cout << i << "--";	
	cout << ((ans<INF)?ans:-1) << endl;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}