#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

vector<int> kmp(string &s){
	int n = s.size();
	vector<int>lps(n+1);

	int i=0,j=-1;
	lps[0]=-1;

	while(i<n){
		while(j!=-1 && s[i]!=s[j]) j=lps[j];
		lps[++i] = ++j;
	}

	return lps;
}

void solve(){
	string s; int num;
	cin >> s >> num;

	vector<int>lps = kmp(s);
	int len = s.length();

	cout << (len-lps[len])*1LL*num + lps[len] << endl;
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