#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define REP(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;

int colpar[N], rowpar[N];
void make(int v){
	rowpar[v]=colpar[v]=v;
}
int Column(int v){
	return ((colpar[v]==v)?v:colpar[v]=Column(colpar[v]));
}
int Row(int v){
	return ((rowpar[v]==v)?v:rowpar[v]=Row(rowpar[v]));
}

void solve(){
	int n,m; cin >> n >> m;

	int a[n][m], b[n][m];

	REP(i,n) REP(j,m){
		cin >> a[i][j];
		make(a[i][j]);
	}

	REP(i,n) REP(j,m) cin >> b[i][j];

	REP(i,n) REP(j,m){
		if(i>0) colpar[a[i][j]] = Column(a[i-1][j]);
		if(j>0) rowpar[a[i][j]] = Row(a[i][j-1]);
	}

	REP(i,n) REP(j,m){
		if(i>0 && Column(b[i][j]) != Column(b[i-1][j])){
			cout << "NO\n";
			return;
		}
		if(j>0 && Row(b[i][j]) != Row(b[i][j-1])){
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
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