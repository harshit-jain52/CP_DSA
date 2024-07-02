#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n,m; cin >> n >> m;
	string s; cin >> s;

	int ind[m];
	for(int i=0;i<m;i++) cin >> ind[i];
	string c; cin >> c;
	
	vector<int>ct(26,0);
	for(int i=0;i<m;i++) ct[c[i]-'a']++;

	int j=0;
	sort(ind,ind+m);
	vector<bool> done(n,false);

	for(int i=0;i<m;i++){
		while(ct[j]<=0) j++;
		if(done[ind[i]-1]) continue;
		
		s[ind[i]-1]='a'+j;
		done[ind[i]-1]=true;
		ct[j]--;
	}

	cout << s << endl;
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