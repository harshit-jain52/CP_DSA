#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
const int M = 1e9+7;
const ll INF = 1e15;

vector<vector<ll>>dist;
vector<vector<bool>>vis;

void solve(){
	int n,s1,s2; cin >> n >> s1 >> s2;
	vector<set<int>>g1(n+1),g2(n+1);

	int m1; cin >> m1;
	for(int i=0;i<m1;i++){
		int a,b; cin >> a >> b;
		g1[a].insert(b);
		g1[b].insert(a);
	}

	int m2; cin >> m2;
	for(int i=0;i<m2;i++){
		int c,d; cin >> c >> d;
		g2[c].insert(d);
		g2[d].insert(c);
	}

	dist.assign(n+1,vector<ll>(n+1,INF));
	vis.assign(n+1,vector<bool>(n+1,false));

	priority_queue<pair<ll,pii>>pq;
	pq.push({0,{s1,s2}});
	dist[s1][s2]=0;

	while(!pq.empty()){
		auto [d,u] = pq.top();
		auto [u1,u2] = u;
		pq.pop();

		if(vis[u1][u2]) continue;
		vis[u1][u2]=true;

		for(int v1: g1[u1]){
			for(int v2: g2[u2]){
				ll wt = abs(v1-v2);
				if(dist[v1][v2]>dist[u1][u2]+wt){
					dist[v1][v2]=dist[u1][u2]+wt;
					pq.push({-dist[v1][v2],{v1,v2}});
				}
			}
		}
	}

	ll ans = INF;
	for(int i=1;i<=n;i++){
		for(int j: g1[i]){
			if(g2[i].find(j)!=g2[i].end()){
				ans = min(ans,dist[i][i]);
			}
		}
	}

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