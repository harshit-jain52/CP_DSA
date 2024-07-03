#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

vector<int> zfunc(string &s){
	int n = s.length();
	vector<int>z(n,0);

	int l=0,r=0;
	for(int i=1;i<n;i++){
		if(i<r) z[i]=min(r-i,z[i-l]);

		while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;

		if(i+z[i]>r){
			l = i;
			r = i+z[i];
		}
	}

	return z;
}

void solve(){
	string s; cin >> s;
	int n = s.length();

	if(n&1){
		cout << 0 << endl;
		return;
	}

	vector<int>z = zfunc(s);
	reverse(s.begin(),s.end());
	vector<int>zrev=zfunc(s);

	// for(int i=0;i<n;i++) cout << z[i]<<" ";

	int ct=0;
	for(int plen=0;plen<=n;plen+=2){
		int rlen=n-plen;
		if(z[plen/2]>=plen/2 && zrev[rlen/2]>=rlen/2) ct++;
	}

	cout << ct << endl;
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