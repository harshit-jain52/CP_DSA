#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9+7;

typedef struct{
	int u;
	int v;
	ll len;
} edge;	

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n,m;
	cin >> n >> m;

	edge e[m];
	for(int i=0;i<m;i++){
		cin >> e[i].u>>e[i].v>>e[i].len;
	}

	vector<ll>dist(n+1,0);

	for(int i=1;i<=n-1;i++){
		for(int j=0;j<m;j++){
			dist[e[j].v] = min(dist[e[j].v],dist[e[j].u]+e[j].len);
		}
	}

	vector<int>par(n+1,-1);
	int start = -1;

	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			if(dist[e[j].v]>dist[e[j].u]+e[j].len){
				dist[e[j].v] = dist[e[j].u]+e[j].len;
				start = e[j].v;
				par[e[j].v]=e[j].u;
			}
		}
	}

	if(start==-1) cout << "NO";
	else{
		cout << "YES" << endl;

		for (int i = 0; i < n; ++i)
            start = par[start];

		vector<int>ans;
		for(int x=start;;x=par[x]){
			ans.push_back(x);
			if(x==start && ans.size()>1) break;
		}
		reverse(ans.begin(),ans.end());
		for(auto it:ans){
			cout << it << " ";
		}
	}

	
}