// #include <bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// #define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// typedef long long ll;
// const int M = 1e9+7;

// int main()
// {
// 	FASTIO
// 	int n; cin >> n;
// 	int h[n];
// 	stack<int>st;

// 	vector<int>num(n+1,0);
// 	for(int i=0;i<n;i++){
// 		cin >> h[i];
// 		while(!st.empty() && h[st.top()]<h[i]) st.pop();
		
// 		int idx = 0;
// 		if(!st.empty()) idx = st.top();

// 		num[idx]++;
// 		num[i]--;

// 		st.push(i);
// 	}

// 	for(int i=1;i<=n;i++) num[i]+=num[i-1];

// 	for(int i=0;i<n;i++) cout << num[i] << " ";
// }
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n; cin >> n;
	int h[n];
	for(int i=0;i<n;i++) cin >> h[i];

	vector<int>st;
	vector<int>ans(n);
	for(int l=n-1;l>=0;l--){
		ans[l]=st.size();
		while(st.size() && h[st.back()]<h[l]) st.pop_back();
		st.push_back(l);
	}

	for(int i=0;i<n;i++) cout << ans[i]<< " ";
}