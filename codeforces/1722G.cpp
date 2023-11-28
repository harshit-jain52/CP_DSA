#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n;
	cin >> n;
	if(n%4==0){
		for(int i=0;i<n;i++) cout << i << " ";
	}
	else if(n%4==3){
		for(int i=1;i<=n;i++) cout << i << " ";
	}
	else if(n%4==1){
		for(int i=2;i<=n;i++) cout << i << " ";
		cout << 0;
	}
	else{
		for(int i=1;i<=n-2;i++) cout << i << " ";
		cout << INT_MAX << " " << INT_MAX-n+2;
	}
	cout << endl;
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