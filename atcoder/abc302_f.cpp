#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int INF = 1e7;

int main()
{
	FASTIO
	int n, m; cin >> n >> m;

	vector<vector<int>>g(n+m);
	vector<int>dist(n+m,INF);
	for(int i=0;i<n;i++){
		int a; cin >> a;
		for(int j=0;j<a;j++){
			int s; cin >> s;
			s--;
			g[i].push_back(n+s);
			g[n+s].push_back(i);
		}
	}

	dist[n]=0;
	queue<int>q;
	q.push(n);

	while(!q.empty()){
		int v = q.front();
		q.pop();

		for(int ch: g[v]){
			if(dist[ch]>dist[v]+1){
				dist[ch]=dist[v]+1;
				q.push(ch);
			}
		}
	}

	cout << ((dist[n+m-1]<INF)?dist[n+m-1]/2-1:-1);
}