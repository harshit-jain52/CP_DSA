#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 998244353;

int main()
{
	FASTIO
	int n,k;
	cin >> n >> k;
	vector<pair<int,int>>seg;
	for(int i=0;i<k;i++){
		int l,r;
		cin >> l >> r;
		seg.push_back({l,r});
	}

	sort(seg.begin(),seg.end());

	vector<int>ways(n,0);
	vector<int>pref(n+1,0);
	ways[0]=1;
	pref[1]=1;

	for(int i=1;i<n;i++){
		for(auto [l,r]: seg){
			if(i-l<0) break;
			int lo = max(i-r,0), hi=i-l;
			ways[i] += (pref[hi+1]-pref[lo]+M)%M;
			ways[i]%=M;
		}
		pref[i+1] = (pref[i]+ways[i])%M;
	}

	cout << ways[n-1];
}