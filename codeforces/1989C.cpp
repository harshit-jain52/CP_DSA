#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	int a[n],b[n];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];

	int negct=0,posct=0;
	int asum=0, bsum = 0;
	for(int i=0;i<n;i++){
		if(a[i]==b[i]){
			if(a[i]==-1) negct++;
			else if(a[i]==1) posct++;
		}
		else{
			if(a[i]>b[i]) asum+=a[i];
			else bsum += b[i];	
		}
	}

	while(negct>0){
		if(asum<bsum) swap(asum,bsum);
		asum--;
		negct--;
	}

	while(posct>0){
		if(asum<bsum) swap(asum,bsum);
		bsum++;
		posct--;
	}

	cout << min(asum,bsum) << endl;
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