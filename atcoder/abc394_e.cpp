#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int INF = 1e6;
typedef pair<int,int> pii;
#define F first
#define S second

int main()
{
	FASTIO
	int n; cin >> n;
	vector<string>c(n);
	vector<vector<int>>dist(n,vector<int>(n,INF));
	vector<vector<bool>>vis(n,vector<bool>(n,false));
	queue<pii>q;

	for(int i=0;i<n;i++){
		cin >> c[i];
		dist[i][i]=0;
		vis[i][i]=true;
		q.push({i,i});
	}


	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j && c[i][j]!='-'){
				dist[i][j]=1;
				q.push({i,j});
				vis[i][j]=true;
			}
		}
	}

	while(!q.empty()){
		auto cur = q.front();
		q.pop();
		auto [u,v]=cur;
		vis[u][v]=true;

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(!vis[i][j] && c[i][u]==c[v][j] && c[i][u]!='-'){
					q.push({i,j});
					vis[i][j]=true;
					dist[i][j]=dist[u][v]+2;
				}
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << (dist[i][j]<INF?dist[i][j]:-1) << " ";
		}
		cout << endl;
	}
}