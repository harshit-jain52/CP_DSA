#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;
#define F first
#define S second

vector<int>g[N];

int main(){
	FASTIO
	int n,m,k; cin >> n >> m >> k;

	vector<vector<int>>g(n+1);
	while(m--){
		int a,b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<int>vis(n+1,-1);
	priority_queue<pair<int,int>>pq;
	while(k--){
		int p,h; cin >> p >> h;
		vis[p]=h;
		pq.push({h,p});
	}

	while(!pq.empty()){
		auto cur = pq.top();
		pq.pop();

		for(int ch: g[cur.S]){
			if(vis[ch]<cur.F-1){
				vis[ch]=cur.F-1;
				pq.push({vis[ch],ch});
			}
		}
	}

	vector<int>ans;
	for(int i=1;i<=n;i++) if(vis[i]!=-1) ans.push_back(i);

	cout << ans.size()<<endl;
	for(int v: ans) cout << v << " ";
}