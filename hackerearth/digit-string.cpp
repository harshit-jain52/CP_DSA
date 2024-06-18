#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

string s;
int n, dp[N];
ll k;
int func(int id){
	if(id==n) return 1;
	if(dp[id]!=-1) return dp[id];

	ll num = 0;
	int ways = 0;

	for(int i=id;i<min(n,id+18);i++){
		int d = s[i]-'0';
		if(num*10<k-d){
			num = num*10+d;
			ways = (ways+func(i+1))%M;
		}
		else break;
	}

	return dp[id]=ways;
}

void solve(){
	memset(dp,-1,sizeof(dp));
	cin >> n >> k;
	cin >> s;

	cout << func(0)<<endl;
}

int main()
{
	FASTIO
	int t; cin >> t;
	while(t--) solve();	
}

// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/digit-string-b0713246/