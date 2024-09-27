#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int M = 1e9+7;
const int N = 5e6+1;
const ll INF = 1e17;
vector<bool>isPrime(N,true);

int main()
{
	FASTIO
	int n,m,h,e; cin >> n >> m >> h >> e;
	vector<vector<pair<int,pii>>>g(n+1);

	while(m--){
		int a,b,s,c; cin >> a >> b >> s >> c;
		g[a].push_back({b,{s,c}});
	}

	vector<int>primes = {1};
	isPrime[0]=isPrime[1]=false;
	for(ll i=2;i<N;i++){
		if(isPrime[i]){
			primes.push_back(i);
			for(ll j=i*i;j<N;j+=i){
				isPrime[j]=false;
			}
		}
	}

	int sz = primes.size();
	vector<ll>val(sz,INF);
	int lo=0,hi=sz-1;
	int ans = -1;

	auto dijkstra = [&](int idx) -> void{
		vector<ll>dist(n+1,INF);
		dist[h]=0;
		priority_queue<pair<ll,int>>pq;
		pq.push({0,h});

		while(!pq.empty()){
			int cur = pq.top().S;
			pq.pop();

			for(auto nxt: g[cur]){
				if(nxt.S.F<primes[idx]) continue;
				if(dist[nxt.F]>dist[cur]+nxt.S.S){
					dist[nxt.F]=dist[cur]+nxt.S.S;
					pq.push({-dist[nxt.F],nxt.F});
				}
			}
		}

		val[idx] = dist[e];
	};

	while(lo<=hi){
		int mid = (lo+hi)/2;
		dijkstra(mid);

		if(val[mid]<INF){
			ans = mid;
			lo = mid+1;
		}
		else hi = mid-1;
	}

	if(ans==-1) cout << 0 << " " << 0;
	else cout << primes[ans] << " " << val[ans]*primes[ans];
}