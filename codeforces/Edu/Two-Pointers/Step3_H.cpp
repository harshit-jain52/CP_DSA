#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n,m,s,A,B;
	cin >> n >> m >> s >> A >> B;

	int a[n], b[m];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int j=0;j<m;j++) cin >> b[j];	

	sort(a,a+n);
	sort(b,b+m);

	int i=n-1,j=m-1;
	ll cost = 0; int wt = 0;

	while(i>=0 && wt+A<=s){
		cost += a[i--];
		wt+=A;
	}

	while(j>=0 && wt+B<=s){
		cost+=b[j--];
		wt+=B;
	}

	ll mxcost = cost;
	i++;
	while(i<n){
		wt-=A;
		wt = max(wt,0);
		cost-=a[i++];

		while(j>=0 && wt+B<=s){
			cost+=b[j--];
			wt+=B;
		}

		mxcost = max(mxcost,cost);
	}

	cout << mxcost;
}