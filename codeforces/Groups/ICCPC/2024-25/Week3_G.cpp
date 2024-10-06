#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
#define F first
#define S second

int solve(){
	int n; cin >> n;
	const int INF = 10*n;

	string s; cin >> s;
	set<int>st;
	for(int i=0;i<n;i++) if(s[i]=='1') st.insert(i);

	vector<pair<int,int>>near(n,{INF,INF});
	
	for(int i=0;i<n;i++){
		auto it = st.lower_bound(i);
		if(it!=st.end()) near[i].S = (*it)-i;
		if(it!=st.begin()){
			it--;
			near[i].F = i-(*it);
		}
	}

	int ans = 0;
	for(int i=0;i<n;i++) ans = max(ans,min(near[i].F,near[i].S));
	vector<bool>mark(n,false), dir(n,false);

	for(int i=0;i<n;i++) dir[i] = (s[i]=='1' && i>0 && i<n-1 && s[i-1]=='0' && s[i+1]=='0');

	for(int i=0;i<n;i++){
		if(near[i].F<near[i].S && ans==near[i].F){
			// cout << i << "here1"<<endl;
			if(!dir[i-near[i].F]) continue;
			if(mark[i-near[i].F]) return ans+1;
			mark[i-near[i].F]=true;
		}
		else if(near[i].S<near[i].F && ans==near[i].S){
			// cout << i << "here2"<<endl;
			if(!dir[i+near[i].S]) continue;
			if(mark[i+near[i].S]) return ans+1;
			mark[i+near[i].S]=true;
		}
		else if(near[i].S==near[i].F && ans==near[i].S){
			// cout << i << "here3"<<endl;
			if(!dir[i-near[i].F] || !dir[i+near[i].S]) continue;
			if(!mark[i-near[i].F]) mark[i-near[i].F]=true;
			else if(!mark[i+near[i].S]) mark[i+near[i].S]=true;
			else return ans+1;
		}
	}

	return ans;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		cout << solve() << endl;
	}
}