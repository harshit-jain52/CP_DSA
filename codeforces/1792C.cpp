#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n;
	cin >> n;
	int p[n+1], pos[n+1];
	vector<int>marked(n+1,false);
	for(int i=1;i<=n;i++){
		cin >> p[i];
		pos[p[i]] = i;
	}
	int last=0;
	for(int i=1;i<n;i++){
		if(pos[i]>pos[i+1]){
			int i1 = min(i,n+1-i);
			int i2 = min(i+1,n-i);
			last = max(last,min(i1,i2));
		}
	}

	if(n%2==1 && last==n/2+1) last--;
	cout << last << endl;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}