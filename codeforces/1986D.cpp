#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	string s; cin >> s;

	if(n==2){
		cout << stoi(s) << endl;
		return;
	}

	int ct0=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0') ct0++;
	}

	if(ct0){
		if(n>3){
			cout << 0 << endl;
			return;
		}
		else{
			if(s[0]=='0' || s[2]=='0'){
				cout << 0 << endl;
				return;
			}
			else{
				int x = s[0]-'0', y = s[2]-'0';
				cout << min(x*y,x+y) << endl;
				return;
			}
		}
	}

	int ans = INT_MAX;
	for(int i=0;i<n-1;i++){
		int num = (s[i]-'0')*10 + (s[i+1]-'0');
		for(int j=0;j<n;j++){
			if(j==i || j==i+1 || s[j]=='1') continue;
			num += (s[j]-'0');
		}
		ans = min(ans,num);
	}

	cout << ans << endl;
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