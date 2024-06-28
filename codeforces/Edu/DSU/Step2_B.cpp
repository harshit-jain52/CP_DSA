#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 3e5+6;

int  par[N];

int Find(int v){
	return ((par[v]==v)?v:par[v]=Find(par[v]));
}

void Union(int u, int v){
	par[u]=Find(v);
}

int main()
{
	FASTIO
	int n; cin >> n;

	for(int i=0;i<n;i++) par[i]=i;

	for(int i=0;i<n;i++){
		int p; cin >> p;
		p--;
		int x = Find(p);

		// cout << p<< " "<<x<<endl;
		
		int nxt = ((x+1)%n);
		Union(x,nxt);

		cout << x+1 << " ";
	}
}