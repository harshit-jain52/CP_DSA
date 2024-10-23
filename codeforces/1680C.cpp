#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int M = 1e9+7;

void solve(){
	string s; cin >> s;
	int n = s.size();

	int ct1 = 0;
	vector<int>pos1;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			pos1.push_back(i);
			ct1++;
		}
	}

	int lo=0,hi=ct1-1;
	int ans=ct1;

	while(lo<=hi){
		int mid = (lo+hi)/2;
		int rem = ct1-mid;
		int mn = INT_MAX;
		for(int i=0;i+rem-1<ct1;i++) mn = min(mn,pos1[i+rem-1]-pos1[i]-rem+1);
		if(mn<=mid){
			ans = mid;
			hi=mid-1;
		}
		else lo=mid+1;
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