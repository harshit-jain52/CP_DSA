#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int M = 1e9+7;
const int INF = 1e8;

int main()
{
	FASTIO
	int r,c; cin >> r >> c;
	vector<vector<int>>A(r,vector<int>(c));
	vector<vector<int>>B(r,vector<int>(c));
	vector<vector<bool>>vis(2*r,vector<bool>(c));
	vector<vector<int>>dist(2*r,vector<int>(c,INF));

	for(int i=0;i<r;i++) for(int j=0;j<c-1;j++) cin >> A[i][j];
	for(int i=0;i<r-1;i++) for(int j=0;j<c;j++) cin >> B[i][j];

	priority_queue<pair<int,pii>>pq;
	pq.push({0,{0,0}});
	dist[0][0]=0;

	while(!pq.empty()){
		auto [_,cur] = pq.top();
		pq.pop();

		auto [i,j] = cur;
		if(vis[i][j]) continue;
		vis[i][j]=true;

		if(i<r){
			if(j+1<c && dist[i][j+1]>dist[i][j]+A[i][j]){
				dist[i][j+1]=dist[i][j]+A[i][j];
				pq.push({-dist[i][j+1],{i,j+1}});
			}

			if(j-1>=0 && dist[i][j-1]>dist[i][j]+A[i][j-1]){
				dist[i][j-1]=dist[i][j]+A[i][j-1];
				pq.push({-dist[i][j-1],{i,j-1}});
			}

			if(i+1<r && dist[i+1][j]>dist[i][j]+B[i][j]){
				dist[i+1][j]=dist[i][j]+B[i][j];
				pq.push({-dist[i+1][j],{i+1,j}});
			}

			if(dist[i+r][j]>dist[i][j]+1){
				dist[i+r][j]=dist[i][j]+1;
				pq.push({-dist[i+r][j],{i+r,j}});
			}
		}
		else{
			if(i-1>=r && dist[i-1][j]>dist[i][j]+1){
				dist[i-1][j]=dist[i][j]+1;
				pq.push({-dist[i-1][j],{i-1,j}});
			}
			if(dist[i-r][j]>dist[i][j]){
				dist[i-r][j]=dist[i][j];
				pq.push({-dist[i-r][j],{i-r,j}});
			}
		}
	}

	// for(int i=0;i<2*r;i++){
	// 	for(int j=0;j<c;j++){
	// 		cout << dist[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << dist[r-1][c-1] << endl;
}