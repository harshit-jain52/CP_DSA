#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int INF = 1e7;
const int N = 51;
const int LOG = 15; // no. of primes till 50

int a[N], dp[N][1<<LOG], prec[51];
int mp[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int n;

void precompute(){
	for(int num=1;num<=50;num++){
		prec[num]=0;
		for(int p=0;p<15;p++) if(num%mp[p]==0) prec[num]+=(1<<p);
	}
}

int func(int id, int mask){
	if(id==n) return 0;
	if(dp[id][mask]!=-1) return dp[id][mask];

	int ct = func(id+1,mask);
	if((prec[a[id]]&mask)==0) ct = max(ct,1+func(id+1,mask|prec[a[id]]));

	return dp[id][mask]=ct;
}

void solve(){
	memset(dp,-1,sizeof(dp));
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];

	cout << func(0,0) << endl;
}

int main()
{
	FASTIO
	precompute();

	int t; cin >> t;
	while(t--) solve();
	
}

// https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/sherlock-and-coprime-subset/