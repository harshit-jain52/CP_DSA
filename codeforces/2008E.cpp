#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

struct node{
	vector<int>oddct,evect;
	node(){
		oddct.assign(26,0);
		evect.assign(26,0);
	}
};

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	vector<vector<int>>oddpref(n,vector<int>(26,0));
	vector<vector<int>>evepref(n,vector<int>(26,0));
	vector<vector<int>>oddsuff(n,vector<int>(26,0));
	vector<vector<int>>evesuff(n,vector<int>(26,0));
	oddpref[0][s[0]-'a']=1;
	if(n&1) oddsuff[n-1][s[n-1]-'a']=1;
	else evesuff[n-1][s[n-1]-'a']=1;

	for(int i=1;i<n;i++){
		if(i&1) evepref[i][s[i]-'a']=1;
		else oddpref[i][s[i]-'a']=1;

		for(int j=0;j<26;j++){
			oddpref[i][j] += oddpref[i-1][j];
			evepref[i][j] += evepref[i-1][j];
		}
	}

	for(int i=n-2;i>=0;i--){
		if(i&1) evesuff[i][s[i]-'a']=1;
		else oddsuff[i][s[i]-'a']=1;

		for(int j=0;j<26;j++){
			oddsuff[i][j] += oddsuff[i+1][j];
			evesuff[i][j] += evesuff[i+1][j];
		}
	}
	int ans = INT_MAX;

	if(n%2==0){
		int oddmx=0, evemx=0;
		for(int j=0;j<26;j++){
			oddmx = max(oddmx, oddpref[n-1][j]);
			evemx = max(evemx, evepref[n-1][j]);
		}
		ans = (n-oddmx-evemx);
	}	
	else{
		for(int i=0;i<n;i++){
			node tmp1,tmp2;
			tmp1.oddct = ((i>0)?oddpref[i-1]:vector<int>(26,0));
			tmp1.evect = ((i>0)?evepref[i-1]:vector<int>(26,0));
			tmp2.oddct = ((i<n-1)?oddsuff[i+1]:vector<int>(26,0));
			tmp2.evect = ((i<n-1)?evesuff[i+1]:vector<int>(26,0));

			int omx=0,emx=0;

			for(int j=0;j<26;j++){
				omx = max(omx, tmp1.oddct[j] + tmp2.evect[j]);
				emx = max(emx, tmp1.evect[j] + tmp2.oddct[j]);
			}
			ans = min(ans, n-omx-emx);
		}
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