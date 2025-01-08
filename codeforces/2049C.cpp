#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

inline int mex(int p, int q){
	if(p!=0 && q!=0) return 0;
	if(p!=1 && q!=1) return 1;
	return 2;
}

void solve(){
	int n,x,y; cin >> n >> x >> y;
	x--; y--;
	vector<int>a(n,-1);
	a[x]=0; a[y]=1;

	for(int i=x,ct=0;ct<n;i=(i+1)%n,ct++){
		if(a[i]!=-1) continue;
		int l = (i-1+n)%n, r = (i+1)%n;

		if(a[l]!=-1 && a[r]!=-1){
			a[i]=mex(a[l],a[r]);
		}
		else if(a[l]!=-1){
			a[i]=1-a[l];
		}
		else a[i]=1-a[r];
	}

	for(int i=0;i<n;i++) cout << a[i] << " ";
	cout << endl;
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