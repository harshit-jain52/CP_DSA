#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;

vector<int>tree[N];
int subSz[N];
int n, P, Q;

void dfs(int v, int p){
	subSz[v]=1;

	for(int ch: tree[v]){
		if(ch==p) continue;
		dfs(ch,v);
		subSz[v] += subSz[ch];
	}

	P += (subSz[v]*1LL*(n-subSz[v]))%M;
	P %= M;
}

int binpow(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = (ans*1LL*a)%M;
		a = (a*1LL*a)%M;
		b >>= 1; 
	}
	return ans;
}

int inverse(int a){
	return binpow(a, M-2);
}

int main()
{
	FASTIO
	cin >> n;
	for(int i=0;i<n-1;i++){
		int a,b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1,0);
	Q = inverse((n*1LL*(n+1)/2)%M);
	cout << (P*1LL*Q)%M;
}