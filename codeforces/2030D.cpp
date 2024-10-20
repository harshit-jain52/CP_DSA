#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n,q; cin >> n >> q;
	int p[n], lmax[n];

	for(int i=0;i<n;i++){
		cin >> p[i];
		p[i]--;
		if(i) lmax[i]=max(lmax[i-1],p[i]);
		else lmax[i]=p[i];
	}

	vector<bool>ok(n,true); int ct=0;

	string s; cin >> s;

	for(int i=1;i<n-1;i++){
		if(s[i]=='L' && s[i+1]=='R' && lmax[i]!=i){
			ok[i]=false;
			ct++;
		}
	}

	while(q--){
		int pos; cin >> pos; pos--;
		if(s[pos]=='L'){
			if(!ok[pos]){
				ok[pos]=true;
				ct--;
			}
			s[pos]='R';
			if(s[pos-1]=='L' && lmax[pos-1]!=pos-1){
				ok[pos-1]=false;
				ct++;
			}
		}
		else{
			if(s[pos-1]=='L' && !ok[pos-1]){
				ok[pos-1]=true;
				ct--;
			}
			s[pos]='L';
			if(s[pos+1]=='R' && lmax[pos]!=pos){
				ok[pos]=false;
				ct++;
			}
		}

		cout << ((ct==0)?"YES\n":"NO\n");
	}
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