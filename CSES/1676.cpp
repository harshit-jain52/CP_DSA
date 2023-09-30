#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

int par[N];
int set_size[N];
int num = N;
int maxsz = 1;

void make(int v){
	par[v]=v;
	set_size[v]=1;
}

int find(int v){
	if(v==par[v]) return v;
	return par[v] = find(par[v]);
}

void unionBySize(int a, int b){
	a = find(a);
	b = find(b);

	if(a==b) return;

	if(set_size[a]<set_size[b]) swap(a,b);

	par[b] = a;
	set_size[a]+=set_size[b];
	num--;
	maxsz = max(maxsz,set_size[a]);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n,m;
	cin >> n >> m;
	num =n;
	for(int i=1;i<=n;i++) make(i);

	while(m--){
		int a, b;
		cin >> a >> b;
		unionBySize(a,b);
		cout << num << " " << maxsz << endl;
	}	
}