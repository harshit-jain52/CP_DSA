#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

vector<int> kmp(vector<int>&s){
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

int main()
{
	FASTIO
	int n; cin >> n;
	int a[n],b[n];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];

	if(n==1){
		cout << 0 << " " << (a[0]^b[0]);
		return 0;
	}

	vector<int>vec;
	for(int i=1;i<n;i++) vec.push_back(b[i]^b[i-1]);
	vec.push_back(b[n-1]^b[0]);
	vec.push_back(-1);

	for(int i=1;i<n;i++) vec.push_back(a[i]^a[i-1]);
	vec.push_back(a[n-1]^a[0]);
	for(int i=1;i<n;i++) vec.push_back(a[i]^a[i-1]);

	vector<int>lps = kmp(vec);
	int base = 2*n+1;

	for(int k=0;k<n;k++){
		if(lps[base+k]>=n){
			cout << k << " " << (a[k]^b[0])<<endl;
		}
	}
}