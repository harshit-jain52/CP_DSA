#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	string s; cin >> s;
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

	int ct=0;
	for(int i=n-1;i>=0;i--) if(z[i]==n-i) ct++;

	cout << ct << endl;
}

int main()
{
	FASTIO
	int t; cin >> t;
	for(int i=1;i<=t;i++){
		cout << "Case "<<i<<": ";
		solve();
	}
}