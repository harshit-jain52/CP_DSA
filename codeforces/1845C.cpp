#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

vector<vector<int>>idx;
vector<vector<int>>dp;
string s,l,r; int m,n;

bool func(int i, int j){
	if(i==m) return (j==n+1);
	if(dp[i][j]!=-1) return dp[i][j];

	int ans = false;
	int lo=l[i]-'0',hi=r[i]-'0'; 
	// cout << lo << " " << hi << endl;
	for(int d=lo;d<=hi;d++){
		if(j==n+1) ans |= func(i+1,j);
		else{
			auto it = upper_bound(idx[d].begin(),idx[d].end(),j);
			ans |= func(i+1,(*it));
		}
	}
	return dp[i][j]=ans;
}

bool solve(){
	cin >> s; n=s.size();
	cin >> m;
	cin >> l >> r;

	dp.assign(m+1,vector<int>(n+2,-1));
	idx.assign(10,vector<int>());

	for(int i=0;i<n;i++) idx[s[i]-'0'].push_back(i+1);
	for(int d=0;d<=9;d++) idx[d].push_back(n+1);
	return func(0,0);
}

int main()
{
	FASTIO
	int t; cin >> t;
	while(t--){
		if(solve()) cout << "YES\n";
		else cout << "NO\n";
	}
}