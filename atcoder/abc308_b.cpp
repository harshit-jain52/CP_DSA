#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n,m; cin >> n >> m;
	string c[n],d[m+1];
	for(int i=0;i<n;i++) cin >> c[i];
	for(int i=1;i<=m;i++) cin >> d[i];
	
	map<string,int>cost;
	int p[m+1];
	for(int i=0;i<=m;i++){
		cin >> p[i];
		if(i) cost[d[i]]=p[i];
	}

	int tot=0;
	for(int i=0;i<n;i++){
		if(cost.find(c[i])!=cost.end()) tot += cost[c[i]];
		else tot += p[0];
	}
	cout << tot;
}