#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

bool solve(){
	int n; cin >> n;
	ll x[n],p[n];
	for(int i=0;i<n;i++) cin >> x[i];
	for(int i=0;i<n;i++) cin >> p[i];

	ll l[n],r[n];
	l[0]=1,r[n-1]=1;

	for(int i=1;i<n;i++){
		l[i]=1; r[n-i-1]=1;

		if(x[i]-p[i]<=x[i-1]) l[i]=1+l[i-1];
		if(x[n-i-1]+p[n-i-1]>=x[n-i]) r[n-i-1] = 1+r[n-i];
	}

	// for(int i=0;i<n;i++) cout << l[i]<<" ";
	// 	cout << endl;

	// for(int i=0;i<n;i++) cout << r[i]<<" ";
	// 	cout << endl;

	for(int i=0;i<n-1;i++) if(l[i]+r[i+1]>=n) return true;

	if(r[0]>=n) return true;
	if(r[0]+r[r[0]]>=n) return true;
	if(l[n-1]>=n) return true;
	if(l[n-1]+l[n-1-l[n-1]]>=n) return true;
	if(l[n-1]+r[0]>=n) return true;

	return false;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		if(solve()) cout << "YES\n";
		else cout << "NO\n";
	}
}