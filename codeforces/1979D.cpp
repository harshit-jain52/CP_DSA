#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n,k;
	cin >> n >> k;
	string s; cin >> s;

	int grp = n/k;

	int ct = 1;
	vector<int>vec;
	for(int i=1;i<n;i++){
		if(s[i]==s[i-1]) ct++;
		else{
			vec.push_back(ct);
			ct=1;
		}

		if(i==n-1) vec.push_back(ct);
	}

	vector<int>chng;	

	for(int i=0;i<vec.size();i++){
		if(vec[i]!=k) chng.push_back(i);

		if(vec[i]>2*k){
			cout << -1;
			return;
		}
	}

	if(chng.empty()){
		cout << n;
		return;
	}

	if(chng.size()==1){
		if(vec[chng[0]]==2*k){
			int sum = 0;
			for(int i=0;i<chng[0];i++) sum+=vec[i];
			if(s[sum]!=s[n-1]) cout << sum+k;
			else cout << -1;
		}
		else cout << -1;
		return;
	}
	if(chng.size()==2){
		if(chng[1]==vec.size()-1){
			int sum = 0;
			for(int i=0;i<chng[0];i++) sum+=vec[i];
			if(s[sum]==s[n-1]){
				if(vec[chng[0]]>k && vec[chng[0]]+vec[chng[1]]==2*k) cout << sum + vec[chng[0]]-k;
				else if(vec[chng[0]]<k && vec[chng[0]]+vec[chng[1]]==k) cout << sum+vec[chng[0]];
				else cout << -1;
			}
			else cout << -1;
			return;
		}
		else cout << -1;
		return;
	}

	cout << -1;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
}