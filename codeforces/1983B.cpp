#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
#define REP(i,n) for(int i=0;i<n;i++)

bool solve(){
	int n,m;
	cin >> n >> m;

	vector<int>arow(n,0), acol(m,0), brow(n,0), bcol(m,0);

	REP(i,n){
		string s; cin >> s;
		REP(j,m){
			int dig = s[j]-'0';
			arow[i]+=dig;
			acol[j]+=dig;
		}
	}

	REP(i,n){
		string s; cin >> s;
		REP(j,m){
			int dig = s[j]-'0';
			brow[i]+=dig;
			bcol[j]+=dig;
		}
	}

	for(int i=0;i<n;i++){
		if(arow[i]%3 != brow[i]%3) return false;
	}

	for(int i=0;i<m;i++){
		if(acol[i]%3 != bcol[i]%3) return false;
	}

	return true;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		if(solve()) cout << "YES\n";
		else cout << "NO\n";
	}
}   