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

int main()
{
	FASTIO
	string s; cin >> s;

	int n = s.size();
	vector<int>z = zfunc(s);
	vector<int>vals = z;

	sort(vals.begin(),vals.end());

	vector<pair<int,int>>ans;
	for(int i=n-1;i>=0;i--){
		if(z[i]==n-i){
			auto it = lower_bound(vals.begin(),vals.end(),z[i]);
			int ct = vals.end()-it;
			ans.push_back({z[i],ct+1});
		}
	}
	ans.push_back({n,1});

	cout << ans.size()<<endl;
	for(auto p: ans) cout << p.first << " "<<p.second<<endl;
}