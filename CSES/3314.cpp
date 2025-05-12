#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int M = 1e9+7;

int main()
{
	FASTIO
	int n; cin >> n;
	int h[n];
	vector<pii>vec;
	for(int i=0;i<n;i++){
		cin >> h[i];
		vec.push_back({h[i],i});
	}

	vector<int> nge(n,-1), pge(n,-1), dp(n,1);
	
	stack<int>st;
	for(int i=n-1;i>=0;i--){
		while(!st.empty() && h[st.top()]<=h[i]) st.pop();
		if(!st.empty()) nge[i]=st.top();
		st.push(i);
	}

	while(!st.empty()) st.pop();
	for(int i=0;i<n;i++){
		while(!st.empty() && h[st.top()]<=h[i]) st.pop();
		if(!st.empty()) pge[i]=st.top();
		st.push(i);
	}

	sort(vec.begin(),vec.end());
	int mx = 1;
	for(int i=n-1;i>=0;i--){
		int idx = vec[i].S;
		if(nge[idx]!=-1) dp[idx] = max(dp[idx],1+dp[nge[idx]]);
		if(pge[idx]!=-1) dp[idx] = max(dp[idx],1+dp[pge[idx]]);
		mx = max(mx,dp[idx]);
	}

	cout << mx;
}