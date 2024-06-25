#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;
const int LOG = 18;
const int INF = 1e7;

int lg2[N];
ll g[N][LOG];

ll query(int l, int r){
	int k = lg2[r-l+1];
	return __gcd(g[l][k],g[r-(1<<k)+1][k]);
}

int main()
{
	FASTIO
	int n; cin >> n;
	ll a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
		g[i][0]=a[i];
	}

	lg2[1]=0;
	for(int i=2;i<=n;i++) lg2[i]=1+lg2[i/2];

	for(int j=1;j<=lg2[n];j++){
		for(int i=0; i+(1<<j)-1<n;i++){
			g[i][j] = __gcd(g[i][j-1],g[i+(1<<(j-1))][j-1]);
		}
	}

	int head = -1, tail=0,len=INF;
	ll curg = 0;

	while(tail<n){
		while(head+1<n && __gcd(curg,a[head+1])>1){
			head++;
			curg = __gcd(curg,a[head]);
		}
		if(head!=n-1) len = min(len,head-tail+2);

		if(head>tail){
			curg = query(tail+1,head);
			tail++;
		}
		else{
			tail++;
			head = tail-1;
			curg = 0;
		}
	}

	cout << ((len<INF)?len:-1);
}