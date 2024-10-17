#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const ll INF = 1e17;

struct Edge{
	int a,b;
	ll c;
	bool open;
	Edge(){a=b=c=0;open=true;}
};

struct Query{
	int tp,i,x,y;
	Query(){tp=i=x=y;}
};

int main()
{
	FASTIO
	int n,m,q; cin >> n >> m >> q;

	vector<Edge>e(m);
	for(int i=0;i<m;i++) cin >> e[i].a >> e[i].b >> e[i].c;

	vector<Query>qu(q);
	for(int i=0;i<q;i++){
		cin >> qu[i].tp;
		if(qu[i].tp==1){
			cin >> qu[i].i;
			qu[i].i--;
			e[qu[i].i].open=false;
		}
		else cin >> qu[i].x >> qu[i].y;
	}

	vector<vector<ll>>dist(n+1,vector<ll>(n+1,INF));
	for(int i=0;i<=n;i++) dist[i][i]=0;

	for(int i=0;i<m;i++){
		if(!e[i].open) continue;
		dist[e[i].a][e[i].b]=dist[e[i].b][e[i].a]=e[i].c;
	}

	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][k]!=INF && dist[k][j]!=INF) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}


	vector<ll>prn;

	for(int p=q-1;p>=0;p--){
		if(qu[p].tp==2) prn.push_back((dist[qu[p].x][qu[p].y]<INF)?dist[qu[p].x][qu[p].y]:-1);
		else{
			int idx = qu[p].i;
			e[idx].open=true;
			dist[e[idx].a][e[idx].b] = min(dist[e[idx].a][e[idx].b],e[idx].c);
			dist[e[idx].b][e[idx].a] = dist[e[idx].a][e[idx].b];

			for(int k : initializer_list<int>{e[idx].a, e[idx].b}){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(dist[i][k]!=INF && dist[k][j]!=INF) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
					}
				}
			}
		}
	}

	reverse(prn.begin(),prn.end());
	for(ll out: prn) cout << out << endl;
}