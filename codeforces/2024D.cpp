#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second
const int M = 1e9+7;
const ll INF = 1e17;

void solve(){
	int n; cin >> n;
	ll a[n], b[n], pref[n];

	for(int i=0;i<n;i++) {
		cin >> a[i];
		if(i) pref[i]=pref[i-1]+a[i];
		else pref[i] = a[i];
	}
	for(int i=0;i<n;i++) {
		cin >> b[i];
		b[i]--;
	}

	priority_queue<pll> pq;
	vector<ll>dist(n,INF);
	dist[0]=0;
	pq.push({0,0});

	while(!pq.empty()){
		int v = pq.top().S;
		pq.pop();

		if(v>0 && dist[v-1]>dist[v]){
			dist[v-1]=dist[v];
			pq.push({-dist[v-1],v-1});
		}
		if(dist[b[v]]>dist[v]+a[v]){
			dist[b[v]]=dist[v]+a[v];
			pq.push({-dist[b[v]],b[v]});
		}
	}

	ll ans = 0;
	for(int i=0;i<n;i++) ans = max(ans,pref[i]-dist[i]);
	cout << ans << endl;
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