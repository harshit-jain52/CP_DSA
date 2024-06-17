#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

vector<int>kmp(string &str){
	int n = str.length();
	vector<int>lps(n+1);

	int i=0,j=-1;
	lps[0]=-1;

	while(i<n){
		while(j!=-1 && str[j]!=str[i]) j=lps[j];

		i++; j++;
		lps[i]=j;
	}

	return lps;
}

int numOfDigits(int num){
	int ct = 0;
	while(num>0){
		ct++;
		num/=10;
	}
	return ct;
}

string s;
int n;
int dp[8010];

int func(int idx){
	if(idx==n) return 0;

	if(dp[idx]!=-1) return dp[idx];

	int len = n-idx;
	string t = s.substr(idx,len);

	int ans = len+1;
	vector<int>lps = kmp(t);

	for(int i=idx;i<n;i++){
		int pref = i-idx+1;
		ans = min(ans,pref+1+func(i+1));

		int p = pref-lps[pref];
		if(pref%p==0) ans = min(ans,p+numOfDigits(pref/p)+func(i+1));	
	}

	return dp[idx] = ans;
}

int main()
{
	FASTIO
	memset(dp,-1,sizeof(dp));
	cin >> s;
	n = s.size();

	cout << func(0);
}