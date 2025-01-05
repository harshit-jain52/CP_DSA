#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
typedef pair<int,int> pii;
#define F first
#define S second

int binpow(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = (ans*1LL*a)%M;
		a = (a*1LL*a)%M;
		b>>=1;
	}
	return ans;
}

int main()
{
	FASTIO
	int n, m;
	cin >> n >> m;

	vector<string>grid(n);
	for(int i=0;i<n;i++) cin >> grid[i];

	vector<pii>surr={{1,0},{-1,0},{0,1},{0,-1}};

	int ct = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			bool flag = true;
			for(auto [dx,dy]: surr){
				if(i+dx<0 || i+dx>=n || j+dy<0 || j+dy>=m) continue;
				flag &= (grid[i][j]==grid[i+dx][j+dy]);
			}
			// if(flag) cout << i << " " << j << endl;
			ct+=flag;
		}
	}
	// cout << ct << endl;
	cout << binpow(2,ct);
}