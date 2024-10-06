#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int M = 1e9+7;
const int N = 1e4+1;

struct Query{
	int idx,m,b;
	
	Query(){
		idx=m=b=0;
	}

	bool operator<(Query &other){
		return m<other.m;
	}
};

int main()
{
	FASTIO
	int n, q;
	cin >> n >> q;

	if(n==0){
		while(q--){
			int m,b; cin >> m >> b;
			cout << 0 << endl;
		}
		return 0;
	}

	vector<pair<int,pii>>vec(n);
	vector<ll>dp(N);

	for(int i=0;i<n;i++){
		int c,m,t; cin >> c >> m >> t;
		vec[i].F = t;
		vec[i].S.F = c;
		vec[i].S.S = m;
	}

	sort(vec.begin(),vec.end());

	vector<Query>quer(q);
	vector<ll>ans(q);

	for(int i=0;i<q;i++){
		quer[i].idx=i;
		cin >> quer[i].m >> quer[i].b;
	}

	sort(quer.begin(),quer.end());
	
	int i = n-1;
	for(int qu=q-1;qu>=0;qu--){
		while(i>=0 && vec[i].F>quer[qu].m){
			for(int j=N-1;j>=0;j--){
				if(vec[i].S.S<=j) dp[j]=max(dp[j],vec[i].S.F+dp[j-vec[i].S.S]);
			}
			i--;
		}
		ans[quer[qu].idx]=dp[quer[qu].b];
	}

	for(int i=0;i<q;i++) cout << ans[i] << endl;
}